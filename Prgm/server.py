import socket
import sys

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
        print("socket error")
        bind_socket()

def socket_accepted():
    conn,address=s.accept()
    send_commands(conn)
    conn.close()

def send_commands(conn):
    while(True):
        cmd=input("Server:")
        if(cmd=="quit"):
            conn.close()
            s.close()
            sys.exit()
        if(len(str(cmd))>0):
            conn.send(str.encode(cmd))
            client_response=conn.recv(1024)
            print("Client:"+client_response.decode())

def main():
    create_socket()
    bind_socket()
    socket_accepted()

main()
            
import socket
import sys
import subprocess

s=socket.socket()
host='localhost'
port=9999
s.connect((host,port))
print("Welcome Client")

while True:
    data=s.recv(1024)
    print("Server:"+data.decode())
    senddata=input("Client:")
    s.send(str.encode(senddata))


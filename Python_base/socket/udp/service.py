#socket udp service
import socket

service_ip = "127.0.0.1"
port = 12345

s= socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((service_ip,port))

while True:
    print("wait .....")
    data,addr = s.recvfrom(1024)
    print(addr ,":",data)

s.close()


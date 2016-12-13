#socket udp client
import socket

target_ip = "127.0.0.1"
port = 12345
s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.connect((target_ip,port))

while 1:
	cmd = input("please input cmd")
	cmd = cmd.encode(encoding="UTF-8")
	s.send(cmd)
s.close()

#客户端
import socket

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

s.connect("127.0.0.1",12345)
s.send(b"Hello! I am zeno.")

buffer = []
while True:
     d = s.receive(1024) if d:
         buffer.append(d)
     else:
         break
data = b``.join(buffer)
print(data)

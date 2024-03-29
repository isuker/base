import socket
import threading

def tcplink(sock,addr):
    print("Accept new connection from %s:"% addr)
    sock.send(b"welcome !")
    while True:
        data = sock.recv(1024)
        time.sleep(1)
        if not data or data.decode('utf-8') == 'exit':
            break
        sock.send(('Hello, %s!' % data.decode('utf-8')).encode('utf-8'))
    sock.close()
    print('Connection from %s:%s closed.' % addr)


s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("127.0.0.1",9999))
s.listen(1)
sock ,addr = s.accept()
while True:
    data = sock.recv(1024)
    print(data)

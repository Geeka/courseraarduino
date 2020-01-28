import socket
import sys

host=""
port=1234
ms=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
ainfo=socket.getaddrinfo(None,1234)
addr1=ainfo[3][4]
try:
	ms.bind(addr1)
except:
	print(sys.exc_info())

ms.listen(5)

while True:
    conn,addr=ms.accept()
    data=conn.recv(1024)
    if not data:
        break
    #conn.sendall(data)
    print("Got a connection\n")

    print("Data recieved\n")
    print(data)

    conn.close()
    ms.close()





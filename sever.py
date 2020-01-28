import socket
import sys

try:
	ms=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	ms.bind(("",1234))
	ms.listen(5)

	conn,addr=ms.accept()
	data=conn.recv(1024)
	
	print("Got a connection")
	print("Bytes of Data recieved",len(data))

	resp=(b"HTTP/1.1 200 OK\r\n")
	conn.sendall(resp)
	conn.close()
except:
	print(sys.exc_info()[1])
finally:
	ms.close()

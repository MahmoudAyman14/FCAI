#TCP Server#

from socket import *
s_port=12000
s_socket=socket(AF_INET,SOCK_STREAM)
s_socket.bind(('',s_port))
s_socket.listen(1)
print('Server Ready To Receive...')
while True:
    connection_socket,add=s_socket.accept()
    while True:
        sentence_=connection_socket.recv(1024).decode()
        print(f"Received message from client: {sentence_}")
        if sentence_=="Exit":
            connection_socket.send("It is disconnect".encode())
            connection_socket.close()
            break

        connection_socket.send(f"length is {len(sentence_)} byets...".encode())
        
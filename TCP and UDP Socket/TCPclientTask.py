#TCP Client#




from socket import *

s_IP=''
s_port=12000
c_socket=socket(AF_INET,SOCK_STREAM)
c_socket.connect((s_IP,s_port))
while True:
        sentence_=input('Enter your message...(if want to disconnect enter Exit) : ')
        c_socket.send(sentence_.encode())
        mod_sentence=c_socket.recv(1024)
        print('From the Server: ',mod_sentence.decode())
        if sentence_=="Exit":
            print("It is Disconnected...")
            c_socket.close()
            break



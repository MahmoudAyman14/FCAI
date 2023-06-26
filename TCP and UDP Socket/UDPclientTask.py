# UDP client Task

from socket import *
import sys
clientPort = str(sys.argv[1])
message = sys.argv[2]
serverIP = '192.168.1.8'
serverPort = 1700
clientSocket = socket(AF_INET,SOCK_DGRAM)
clientSocket.bind( ('', clientPort) )
clientSocket.sendto(message.encode(),(serverIP, serverPort))
modifiedMessage, serverAddress =clientSocket.recvfrom(2048)
print (modifiedMessage.decode())
clientSocket.close()
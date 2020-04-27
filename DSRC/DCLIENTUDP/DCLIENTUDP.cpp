#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <iostream>

#ifndef __DCLIENTUDP__
#include "DCLIENTUDP.h"
#endif

DCLIENTUDP::DCLIENTUDP() { 
    std::cout << "\t\tDCLIENTUDP ACTIVE\n"; 
}

DCLIENTUDP::~DCLIENTUDP() { 

}

// Virtual function override
void DCLIENTUDP::defaultSetup() { 
	openSocket(AF_INET, SOCK_DGRAM, 0); 
    setPortNumber(4444);
	populateSocketStruct(0); 

}

void DCLIENTUDP::populateSocketStruct(int domain) { 
    memset(&serv_addr, 0, sizeof(serv_addr)); 
      
    // Filling server information 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(portno); 
    serv_addr.sin_addr.s_addr = INADDR_ANY; 
}

void DCLIENTUDP::closeConnection() { 
    close(sockfd); 
}

void DCLIENTUDP::readMsg() { 

    char msg[1024]; 

	n = recvfrom(sockfd, (char *)msg, 1024, MSG_WAITALL, (struct sockaddr *) &serv_addr, &len); 

    std::cout << "\tReading msg: " << msg << "\n"; 

}

void DCLIENTUDP::sendMsg(std::string msg) { 

    sendto(sockfd, (const char *)msg.c_str(), strlen(msg.c_str()), MSG_CONFIRM, (const struct sockaddr *) &serv_addr, sizeof(serv_addr)); 

}

void DCLIENTUDP::demo() { 
	defaultSetup(); 
	sendMsg("Hello there."); 
	readMsg(); 
	closeConnection(); 
}

// Class specific functions
void DCLIENTUDP::getServer(std::string address) { 

}

void DCLIENTUDP::connectToServer() { 

}
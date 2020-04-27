#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

#ifndef __DSERVERUDP__
#include "DSERVERUDP.h"
#endif

DSERVERUDP::DSERVERUDP() { 
    std::cout << "\t\tDSERVERUDP ACTIVE\n"; 
}

DSERVERUDP::~DSERVERUDP() { 

}

// Virtual function override
void DSERVERUDP::defaultSetup() { 
	openSocket(AF_INET, SOCK_DGRAM, 0); 
    setPortNumber(4444);
	populateSocketStruct(0); 
	bindSocketAndStructure(); 
}

void DSERVERUDP::populateSocketStruct(int domain) { 
    memset(&serv_addr, 0, sizeof(serv_addr)); 
    memset(&cli_addr, 0, sizeof(cli_addr)); 
      
    // Filling server information 
    serv_addr.sin_family    = AF_INET; // IPv4 
    serv_addr.sin_addr.s_addr = INADDR_ANY; 
    serv_addr.sin_port = htons(portno); 
}

void DSERVERUDP::closeConnection() { 
    close(sockfd);
}

void DSERVERUDP::readMsg() { 
     
    char msg[1024]; 
  
    len = sizeof(cli_addr);  //len is value/resuslt 
  
    n = recvfrom(sockfd, (char *)msg, 1024, MSG_WAITALL, ( struct sockaddr *) &cli_addr, &len); 

    std::cout << "\tReading msg: " << msg << "\n"; 

}

void DSERVERUDP::sendMsg(std::string msg) { 

    sendto(sockfd, (const char *)msg.c_str(), strlen(msg.c_str()), MSG_CONFIRM, (const struct sockaddr *) &cli_addr, len); 

}

void DSERVERUDP::demo() { 
	defaultSetup(); 
	readMsg(); 
	sendMsg("General Kenobi!"); 
	closeConnection(); 
}


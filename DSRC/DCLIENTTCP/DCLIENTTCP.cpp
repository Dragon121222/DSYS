
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <iostream>

#ifndef __DCLIENTTCP__
#include "DCLIENTTCP.h"
#endif

DCLIENTTCP::DCLIENTTCP() { 
    std::cout << "\t\tDCLIENTTCP ACTIVE\n"; 
}

DCLIENTTCP::~DCLIENTTCP() { 

}

void DCLIENTTCP::defaultSetup() { 
    setPortNumber(4444);
    openSocket(AF_INET, SOCK_STREAM, 0); 
    getServer("192.168.0.3"); 
    populateSocketStruct(AF_INET);
} 

void DCLIENTTCP::populateSocketStruct(int domain) { 
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
}

void DCLIENTTCP::closeConnection() { 
    std::cout << "Closing Connection\n"; 
    close(sockfd);
}

void DCLIENTTCP::readMsg() { 

    char msg[1024]; 

    n = read(sockfd,msg,1024);

    if (n < 0) {
         error("ERROR reading from socket");        
    }

    std::cout << "\tReading Msg: " << msg << "\n"; 

}

void DCLIENTTCP::sendMsg(std::string msg) {

    // Documentation https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/unistd.h/write

    n = write(sockfd,msg.c_str(),1024);

    if (n < 0) {
         error("ERROR writing to socket");      
    }

}

void DCLIENTTCP::demo() { 
    defaultSetup(); 
    connectToServer();
    sendMsg("Hello there!\n"); 
    readMsg(); 
    closeConnection();  
}


void DCLIENTTCP::getServer(std::string address) { 

    server = gethostbyname(address.c_str());

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

}

void DCLIENTTCP::connectToServer() { 

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

}


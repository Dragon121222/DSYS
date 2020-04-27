#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

#ifndef __DSERVERTCP__
#include "DSERVERTCP.h"
#endif

DSERVERTCP::DSERVERTCP() { 
    std::cout << "\t\tDSERVERTCP ACTIVE\n"; 
}

DSERVERTCP::~DSERVERTCP() { 

}

void DSERVERTCP::defaultSetup() { 
    openSocket(AF_INET, SOCK_STREAM, 0); 
    setPortNumber(4444); 
    populateSocketStruct(AF_INET); 
    bindSocketAndStructure(); 
}

void DSERVERTCP::listenAndAccept() { 
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        error("ERROR on accept");
    } else { 
        std::cout << "Connection Established\n"; 
    }
} 

void DSERVERTCP::populateSocketStruct(int domain) { 
    // Documentation: https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
    bzero( (char *) &serv_addr, sizeof(serv_addr) );
    serv_addr.sin_family = domain;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
}

void DSERVERTCP::readMsg() { 

    char msg[1024]; 

    n = read(newsockfd,msg,1024);

    if (n < 0) {
         error("ERROR reading from socket");        
    }

    std::cout << "\t\t\tReading Msg: " << msg << "\n"; 

}

void DSERVERTCP::sendMsg(std::string msg) {

    // Documentation https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/unistd.h/write

    n = write(newsockfd,msg.c_str(),1024);

    if (n < 0) {
         error("ERROR writing to socket");      
    }

}

void DSERVERTCP::closeConnection() { 
    std::cout << "Closing Connection\n"; 
    close(newsockfd);
    close(sockfd);
}

void DSERVERTCP::demo() { 
    defaultSetup(); 
    listenAndAccept(); 
    readMsg();  
    sendMsg("General Kenobi"); 
    closeConnection(); 
}


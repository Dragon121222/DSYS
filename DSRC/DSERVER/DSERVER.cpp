#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

#ifndef __DSERVER__
#include "DSERVER.h"
#endif

DSERVER::DSERVER() { 
    std::cout << "\tDSERVER ACTIVE\n"; 
}

DSERVER::~DSERVER() { 

}

void DSERVER::error(const char *msg) {
    perror(msg);
    exit(1);
}

void DSERVER::openSocket(int domain, int type, int protocol) { 

    // Documentation: https://pubs.opengroup.org/onlinepubs/009695399/functions/socket.html

    sockfd = socket(domain, type, protocol);

    if (sockfd < 0) { 
        error("ERROR opening socket");
    }

}

void DSERVER::setPortNumber(int portNumber) { 
    portno = portNumber;
}    

void DSERVER::populateSocketStruct(int domain) { 
    // Documentation: https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
    bzero( (char *) &serv_addr, sizeof(serv_addr) );
    serv_addr.sin_family = domain;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
}

void DSERVER::bindSocketAndStructure() { 
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");    
    }
}


void DSERVER::listenAndAccept() { 
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        error("ERROR on accept");
    }
} 

void DSERVER::readMsg() { 

    int size[1]; 

    n = read(newsockfd,(void*)size,sizeof(int[1]));

    char msg[size[0]/sizeof(char)]; 

    n = read(newsockfd,msg,size[0]);

    if (n < 0) {
         error("ERROR reading from socket");        
    }

    std::cout << "\tReading Msg: " << msg << "\n"; 

}

void DSERVER::sendMsg(std::string msg) {

    // Documentation https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/unistd.h/write

    std::cout << "\tSending Msg: " + msg + "\n"; 

    int msgSize[1] = {sizeof(msg)}; 

    n = write(newsockfd,(void*)msgSize,sizeof(int[1]));

    n = write(newsockfd,msg.c_str(),msgSize[0]);

    if (n < 0) {
         error("ERROR writing to socket");      
    }

}


void DSERVER::closeConnection() { 
    close(newsockfd);
    close(sockfd);
}

void DSERVER::demo() { 
    openSocket(AF_INET, SOCK_STREAM, 0); 
    setPortNumber(3490); 
    populateSocketStruct(AF_INET); 
    bindSocketAndStructure(); 
    listenAndAccept(); 
    readMsg();  
    sendMsg("General Kenobi"); 
    closeConnection(); 
}


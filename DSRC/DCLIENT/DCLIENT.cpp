
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <iostream>

#ifndef __DCLIENT__
#include "DCLIENT.h"
#endif

DCLIENT::DCLIENT() { 
    std::cout << "\tDCLIENT ACTIVE\n"; 
}

DCLIENT::~DCLIENT() { 

}

void DCLIENT::error(const char *msg) {
    perror(msg);
    exit(1);
}

void DCLIENT::setPortNumber(int portNumber) { 
    portno = portNumber;
}    

void DCLIENT::openSocket(int domain, int type, int protocol) { 

    // Documentation: https://pubs.opengroup.org/onlinepubs/009695399/functions/socket.html

    sockfd = socket(domain, type, protocol);

    if (sockfd < 0) { 
        error("ERROR opening socket");
    }

}

void DCLIENT::getServer(std::string address) { 

    server = gethostbyname(address.c_str());

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

}

void DCLIENT::populateSocketStruct(int domain) { 

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

}


void DCLIENT::connectToServer() { 

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

}


void DCLIENT::readMsg() { 

    int size[1]; 

    n = read(sockfd,(void*)size,sizeof(int[1]));

    char msg[size[0]/sizeof(char)]; 

    n = read(sockfd,msg,size[0]);

    if (n < 0) {
         error("ERROR reading from socket");        
    }

    std::cout << "\tReading Msg: " << msg << "\n"; 

}


void DCLIENT::read_Msg() { 

    char msg[1024]; 

    n = read(sockfd,msg,sizeof(msg));

    if (n < 0) {
         error("ERROR reading from socket");        
    }

    std::cout << "\tReading Msg: " << msg << "\n"; 

}

void DCLIENT::sendMsg(std::string msg) {

    // Documentation https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/unistd.h/write

    std::cout << "\tSending Msg: " + msg + "\n"; 

    int msgSize[1] = {sizeof(msg)}; 

    n = write(sockfd,(void*)msgSize,sizeof(int[1]));

    n = write(sockfd,msg.c_str(),msgSize[0]);

    if (n < 0) {
         error("ERROR writing to socket");      
    }

}

void DCLIENT::send_Msg(std::string msg) {

    // Documentation https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/unistd.h/write

    std::cout << "\tSending Msg: " + msg + "\n"; 

    const char * m = msg.c_str(); 

    n = write(sockfd,m,sizeof(msg));

    if (n < 0) {
         error("ERROR writing to socket");      
    }

}

void DCLIENT::send_Msg(const char * msg) {

    // Documentation https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/unistd.h/write

    std::cout << "\tSending Msg: "; 
    for(int i = 0; i < sizeof(msg)/sizeof(unsigned int); i++) { 
        std::cout << msg[i] << " "; 
    }

    n = write(sockfd,msg,sizeof(msg));

    if (n < 0) {
         error("ERROR writing to socket");      
    }

}

void DCLIENT::send_Msg(unsigned char * msg, int size) {

    // Documentation https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/unistd.h/write

    n = write(sockfd,msg,size);

    if (n < 0) {
         error("ERROR writing to socket");      
    }

}

void DCLIENT::closeSocket() { 
    close(sockfd);
}

void DCLIENT::demo() { 
	setPortNumber(4444);
    openSocket(AF_INET, SOCK_STREAM, 0); 
	getServer("192.168.0.3"); 
	populateSocketStruct(AF_INET);
	connectToServer();
	sendMsg("Hello there!\n"); 
	readMsg(); 
	closeSocket(); 
}

void DCLIENT::unityClientExample() { 

	setPortNumber(4444);
//    openSocket(AF_INET, SOCK_DGRAM, 0); 
    openSocket(AF_INET, SOCK_STREAM, 0); 
	getServer("192.168.0.3"); 
	populateSocketStruct(AF_INET);
	connectToServer();
    send_Msg("Hello there!\n"); 
    read_Msg(); 
	closeSocket(); 

}

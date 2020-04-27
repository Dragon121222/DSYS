#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

#ifndef __DNETWORK__
#include "DNETWORK.h"
#endif

DNETWORK::DNETWORK() { 
    std::cout << "\tDNETWORK ACTIVE\n"; 
}

DNETWORK::~DNETWORK() { 

}

void DNETWORK::error(const char *msg) {
    perror(msg);
    exit(1);
}

void DNETWORK::openSocket(int domain, int type, int protocol) { 

    // Documentation: https://pubs.opengroup.org/onlinepubs/009695399/functions/socket.html

    sockfd = socket(domain, type, protocol);

    if (sockfd < 0) { 
        error("ERROR opening socket");
    }

}

void DNETWORK::setPortNumber(int portNumber) { 
    portno = portNumber;
}    

void DNETWORK::bindSocketAndStructure() { 
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");    
    }
}

void DNETWORK::defaultSetup() { 
    std::cout << "defaultSetup\n";
}

void DNETWORK::populateSocketStruct(int domain) { 
    std::cout << "populateSocketStruct\n";
}

void DNETWORK::closeConnection() { 
    std::cout << "closeConnection\n";
}

void DNETWORK::readMsg() { 
    std::cout << "readMsg\n";
}

void DNETWORK::sendMsg(std::string msg) { 
    std::cout << "sendMsg\n";
}

void DNETWORK::demo() { 
    std::cout << "demo\n";
}
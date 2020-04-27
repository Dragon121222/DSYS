//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DSERVERTCP__
#define __DSERVERTCP__

#ifndef __DNETWORK__
#include "../DNETWORK/DNETWORK.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

class DSERVERTCP : public DNETWORK {

    public: 

        // Constructor / Deconstructors
        DSERVERTCP(); 
        ~DSERVERTCP(); 

        // Virtual function override
        void defaultSetup(); 
        void populateSocketStruct(int domain);         
        void closeConnection(); 

        void readMsg(); 
        void sendMsg(std::string msg); 

        void demo(); 

        // Class specific functions

        void listenAndAccept(); 
        void establishMsgSize(int size); 

    private: 
/*
        int sockfd, newsockfd, portno;
        socklen_t clilen;
        char buffer[256];
        struct sockaddr_in serv_addr, cli_addr;
        int n;
*/



};

#endif
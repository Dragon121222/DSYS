//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DSERVER__
#define __DSERVER__

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

class DSERVER : public DOBJ {

    public: 

        DSERVER(); 
        ~DSERVER(); 

        void error(const char *msg); 
        void openSocket(int domain, int type, int protocol); 
        void setPortNumber(int portNumber); 
        void populateSocketStruct(int domain); 
        void bindSocketAndStructure(); 
        void listenAndAccept(); 
        void closeConnection(); 
        void readMsg(); 
        void sendMsg(std::string msg); 
        void establishMsgSize(int size); 

        void demo(); 


    private: 

        int sockfd, newsockfd, portno;
        socklen_t clilen;
        char buffer[256];
        struct sockaddr_in serv_addr, cli_addr;
        int n;




};

#endif
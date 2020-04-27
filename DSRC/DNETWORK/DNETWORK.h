//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DNETWORK__
#define __DNETWORK__

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

class DNETWORK : public DOBJ {

    public: 

        DNETWORK(); 
        ~DNETWORK(); 

        void error(const char *msg); 
        void openSocket(int domain, int type, int protocol); 
        void setPortNumber(int portNumber); 
        void bindSocketAndStructure(); 

        virtual void defaultSetup(); 
        virtual void populateSocketStruct(int domain);         
        virtual void closeConnection(); 

        virtual void readMsg(); 
        virtual void sendMsg(std::string msg); 

        virtual void demo(); 


    protected: 

        int sockfd, newsockfd, portno;
        socklen_t clilen;
        char buffer[256];
        struct sockaddr_in serv_addr, cli_addr;
        int n;
        socklen_t len; 




};

#endif
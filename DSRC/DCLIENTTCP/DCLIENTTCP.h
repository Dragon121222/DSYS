//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DCLIENTTCP__
#define __DCLIENTTCP__

#ifndef __DNETWORK__
#include "../DNETWORK/DNETWORK.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <iostream>
#include <string>

class DCLIENTTCP : public DNETWORK { 

	public: 

		DCLIENTTCP(); 
		~DCLIENTTCP(); 

        // Virtual function override
        void defaultSetup(); 
        void populateSocketStruct(int domain);         
        void closeConnection(); 

        void readMsg(); 
        void sendMsg(std::string msg); 

        void demo(); 

        // Class specific functions
		void getServer(std::string address); 
		void connectToServer();

	private: 
/*
		int sockfd, portno, n;
		struct sockaddr_in serv_addr;
*/
		struct hostent *server;

};

#endif
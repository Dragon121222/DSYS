//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DCLIENT__
#define __DCLIENT__

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
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

class DCLIENT : public DOBJ { 

	public: 

		DCLIENT(); 
		~DCLIENT(); 

		void error(const char *msg);
		void setPortNumber(int portNumber);
		void openSocket(int domain, int type, int protocol);
		void getServer(std::string address); 
		void populateSocketStruct(int domain);
		void connectToServer();

		void sendMsg(std::string msg); 
		void send_Msg(std::string msg); 
		void send_Msg(const char * msg);
		void send_Msg(unsigned char * msg, int size); 

		void read_Msg(); 		
		void readMsg(); 
		void closeSocket(); 

		// Applications
		void demo(); 
		void unityClientExample(); 

	private: 

		int sockfd, portno, n;
		struct sockaddr_in serv_addr;
		struct hostent *server;

};

#endif
//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DSERVERUDP__
#define __DSERVERUDP__

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

class DSERVERUDP : public DNETWORK {

    public: 

        // Constructor / Deconstructors
        DSERVERUDP(); 
        ~DSERVERUDP(); 

        // Virtual function override
        void defaultSetup(); 
        void populateSocketStruct(int domain);         
        void closeConnection(); 

        void readMsg(); 
        void sendMsg(std::string msg); 

        void demo(); 

    private: 




};

#endif
//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#include "DOBJ.h"

#ifndef __DLLC__
#define __DLLC__

class DLLC : public DOBJ { 

	public: 

		DLLC(); 
		~DLLC(); 

		// Low Level Code
		void itos(unsigned int x, char poz); 

		// Test Function 
		void unitTests(); 

	private: 

		char sendBuf[255];

}; 

#endif
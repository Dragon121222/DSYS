//****************************************************************************************************************
// Written By Daniel Drake 
// Drake's Low Level Code Tester Class
//****************************************************************************************************************

#include "../DOBJ/DOBJ.h"

#ifndef __DLLC__
#define __DLLC__

class DLLC : public DOBJ { 

	public: 

		 DLLC(); 
		~DLLC(); 

		// Low Level Code
		void itos3(unsigned int x, char poz); 
		void itos4(unsigned int x, char poz); 		
		void fillBufWithNull(void); 
		void memCpyOp(); 
		void memMoveOp();
		int mmw(int p); 
		unsigned char * sw(unsigned int p,unsigned char * s);
		unsigned int sr(unsigned char * s); 
		unsigned int M(unsigned int a, unsigned int b); 
		unsigned int A(unsigned int a, unsigned int b); 		
		char R(unsigned int a, unsigned int b);
		void memSetTest(); 


		// Test Function 
		void unitTests(); 

	private: 

		char sendBuf[255];

}; 

#endif
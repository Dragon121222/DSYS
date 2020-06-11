#include <iostream>
#include <string.h>


#ifndef __DLLC__
#include "DLLC.h"
#endif

DLLC::DLLC() { 
    std::cout << "\tDLLC ACTIVE\n"; 
}

DLLC::~DLLC() { 

}

//#define __MEMCPYOP_TEST__
void DLLC::memCpyOp() { 

    char preset[6];

    itos3(123,0); 
    itos3(456,3); 
    itos3(789,6); 
    itos3(123,9); 
    itos3(456,12); 
    itos3(789,15);     

    memcpy(preset, &sendBuf[6], 5); // preset <- sendBuf // Copy the 5 bytes after position 6 in sendBuf

	std::cout << "Preset Buf Data: " << preset << "\n"; 

}

#define __MEMMOVE_TEST__
void DLLC::memMoveOp() { 

	char a[] = "01234567890000";
	char b[] = "000000000000";

	std::cout << "a: " << a << "\n" << std::flush; 
	std::cout << "b: " << b << "\n" << std::flush; 

	memmove(&b[0],&a[0],4); 

	std::cout << "a: " << a << "\n" << std::flush; 
	std::cout << "b: " << b << "\n" << std::flush; 

}

//#define __ITOS3_TEST__
void DLLC::itos3(unsigned int x, char poz) {  
	if(x < 1000) { 
		char i;
		i = x / 100;
		x = x - i * 100;
		i = i & 0x0f;
		i = i + 48; //'0'..'9'
		sendBuf[poz++] = i;

		i = x / 10;
		x = x - i * 10;
		i = i & 0x0f;
		i = i + 48; //'0'..'9'
		sendBuf[poz++] = i;

		i = x;
		i = i & 0x0f;
		i = i + 48; //'0'..'9'
		sendBuf[poz++] = i;
	} else { 
		std::cout << "Error\n"; 
	}

}

//#define __ITOS4_TEST__
void DLLC::itos4(unsigned int x, char poz) {
  
	char i;
	i = x / 1000;
	x = x - i * 1000;
	i = i & 0x0f;
	i = i + 48; //'0'..'9'
	sendBuf[poz++] = i;

	i = x / 100;
	x = x - i * 100;
	i = i & 0x0f;
	i = i + 48; //'0'..'9'
	sendBuf[poz++] = i;

	i = x / 10;
	x = x - i * 10;
	i = i & 0x0f;
	i = i + 48; //'0'..'9'
	sendBuf[poz++] = i;

	i = x;
	i = i & 0x0f;
	i = i + 48; //'0'..'9'
	sendBuf[poz++] = i;

}

void DLLC::fillBufWithNull(void) {
   int i;
   for (i=1; i<256; i++) { 
      sendBuf[i] = '0';
   }
}

void DLLC::unitTests() { 

	#ifdef __ITOS4_TEST__
		unsigned int x = 54321; 
		char i = 5; 
		fillBufWithNull(); 
		itos4(x,i); 
		std::cout << "sendBuf Data: " << sendBuf << "\n"; 
	#endif

	#ifdef __MEMCPYOP_TEST__
		memCpyOp(); 
		std::cout << "sendBuf Data: " << sendBuf << "\n"; 		
	#endif

	#ifdef __MEMMOVE_TEST__
		memMoveOp(); 
	#endif

}

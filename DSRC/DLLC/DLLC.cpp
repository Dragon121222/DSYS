#ifndef __DLLC__
#include "DLLC.h"
#endif

DLLC::DLLC() { 
    std::cout << "\t\tDLLC ACTIVE\n"; 
}

DLLC::~DLLC() { 

}

void DLLC::itos(unsigned int x, char poz) {  

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

}

void DLLC::unitTests() { 

}

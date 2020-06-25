#include <iostream>
#include <string.h>
#include <cstring>

#ifndef __DLLC__
#include "DLLC.h"
#endif

DLLC::DLLC() { 
    std::cout << "\tDLLC ACTIVE\n"; 
}

DLLC::~DLLC() { 

}

#define __mem_set_test__
void DLLC::memSetTest() { 

    char timout[5];

    printf("timeout %s\n" , timout); 

    memset(timout,'a',5); 

    printf("timeout %s\n" , timout); 

}

//#define __R_test__
char DLLC::R(unsigned int a, unsigned int b) { 
	if(a < b) { 
		std::cout << std::hex << "0x" << a << " < 0x" << b << "\n"; 
		std::cout << std::dec << a << " < " << b << "\n"; 
		return '<'; 
	} else if (a > b) { 
		std::cout << std::hex << "0x" << a << " > 0x" << b << "\n"; 
		std::cout << std::dec << a << " > " << b << "\n"; 
		return '>';
	} else { 
		std::cout << std::hex << "0x" << a << " = 0x" << b << "\n"; 
		std::cout << std::dec << a << " = " << b << "\n"; 
		return '='; 
	}
}

//#define __A_test__
unsigned int DLLC::A(unsigned int a, unsigned int b) { 
	std::cout << std::hex << "0x" << a << " + 0x" << b << " = 0x" << a+b << "\n"; 
	std::cout << std::dec << a << " + " << b << " = " << a+b << "\n"; 
	return a+b; 
}

//#define __M_test__
unsigned int DLLC::M(unsigned int a, unsigned int b) { 
	std::cout << std::hex << "0x" << a << " * 0x" << b << " = 0x" << a*b << "\n"; 
	std::cout << std::dec << a << " * " << b << " = " << a*b << "\n"; 
	return a*b; 
}

//#define __mmw_test__
int DLLC::mmw(int p) { 
	std::cout << std::hex << "p: " << p << "\n"; 
	return p; 
}

//#define __sw_test__
unsigned char * DLLC::sw(unsigned int p,unsigned  char * s) { 
	s[0] = (unsigned char)p; 
	s[1] = (unsigned char)(p>>8); 
	return s; 
}

//#define __sr_test__
unsigned int DLLC::sr(unsigned char * s) { 
	unsigned int a = s[0];  
 	a << 8; 
 	a = a | s[1]; 
 	return a; 
}

//#define __MEMCPYOP_TEST__
void DLLC::memCpyOp() { 

    char preset[5];

    itos3(123,0); 
    itos3(456,3); 
    itos3(789,6); 
    itos3(123,9); 
    itos3(456,12); 
    itos3(789,15);     

    memcpy(preset, &sendBuf[6], 5); // preset <- sendBuf // Copy the 5 bytes after position 6 in sendBuf

	std::cout << "Preset Buf Data: " << preset << "\n"; 

}

//#define __MEMMOVE_TEST__
void DLLC::memMoveOp() { 

	char a[] = "41234567896969";
	char b[] = "000000000000";

	std::cout << "a: " << a << "\n" << std::flush; 
	std::cout << "b: " << b << "\n" << std::flush; 

	memmove(&b[0],&a[3],4); 

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

		fillBufWithNull(); 

		unsigned int a = 05; 
		unsigned int b = 061; 
		unsigned int c = 062; 
		unsigned int d = 063; 		
		unsigned int e = 025; 
		unsigned int f = 0001; 

		itos3(a,0); 		
		itos3(b,3); 
		itos3(c,6); 
		itos3(d,9);
		itos3(e,12);
		itos4(f,15); 		 		 

		std::cout << "sendBuf Data: " << sendBuf << "\n"; 

		a = 0; 
		b = 0; 
		c = 0; 
		d = 0;
		e = 0;
		f = 0;		

		char timeout[4]; 
		












	#endif

	#ifdef __MEMCPYOP_TEST__
		memCpyOp(); 
		std::cout << "sendBuf Data: " << sendBuf << "\n"; 		
	#endif

	#ifdef __MEMMOVE_TEST__
		memMoveOp(); 
	#endif

	#ifdef __mmw_test__
		int x = 0x40; 
		mmw(x++);
		mmw(x++);
		mmw(x++);
		mmw(x++);
		mmw(x++);
		mmw(x);
		x+=2; 

		for(int i = 0; i < 4; i++) { 
			std::cout << "*\n";
			mmw(x++);
			mmw(x++);
			mmw(x++);
			std::cout << "*\n";
		}
	    for (int i = 0; i<6; i++) {
    	    mmw(x++);           
	    }

	    std::cout << std::hex << "FV: " << x << "\n"; 
		std::cout << "***************************\n";
	    x = 0x60; 

	    for(int i = 0; i < 12; i++) { 
			std::cout << "*\n";
        	mmw(x); x+=2;     
        	mmw(x); x+=2;            
        	mmw(x); x+=2;           
        	mmw(x); x+=2;            
        	mmw(x); x+=2;              
        	mmw(x); x+=2;            
        	mmw(x++);           
        	mmw(x++);      
        	mmw(x++);                
			std::cout << "*\n";
	    }

		std::cout << "*\n";

	    x = 0x120;
	    for (int i = 0; i<12; i++) {
    		mmw(x++); // 0x120 -> 0x12c
	    }

	#endif

	#ifdef __sw_test__ 
	    int x = 150; 
	    unsigned char s[2]; 
	    sw(x,s); 
	    std::cout << "s: " << s[0] << s[1] << "\n"; 
	    #ifdef __sr_test__
	    	std::cout << sr(s) << "\n"; 
	    #endif
	#endif

	#ifdef __M_test__
		M(0x06,15); 
	#endif

	#ifdef __A_test__
		int x =	A(0x5a,0x60);
		x =	A(x,2);
		x =	A(x,2);
		x =	A(x,2);
		x =	A(x,2);
		x =	A(x,2);
		x =	A(x,2);
	#endif

	#ifdef __R_test__
		R(0xa5,0x105); 
	#endif

	#ifdef __mem_set_test__
		memSetTest(); 
	#endif

}

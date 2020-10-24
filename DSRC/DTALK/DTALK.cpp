//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DTALK__
#include "DTALK.h"
#endif

DTALK::DTALK() { 
	setPath("./DSRC/DTALK/audioTextFiles/");
	setName("demo.txt");
}

DTALK::~DTALK() { 
	
	if(DF != NULL) { 
		delete(DF); 
	}

}

void DTALK::say(std::string text) { 

	DF = new DFILE(); 

	DF->setPath(path); 
	DF->setName(fname);

	DF->open('x'); 
	DF->write(text); 
	DF->close(); 

	std::string cmd = "espeak -f "; 
	cmd = cmd + path + fname;  

	system(cmd.c_str()); 

}

void DTALK::setPath(std::string p) { 
	path = p; 
}

void DTALK::setName(std::string n) { 
	fname = n; 
}
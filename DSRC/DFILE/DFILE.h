
//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************


#ifndef __DFILE__
#define __DFILE__

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
#endif

#include <string>
#include <iostream>
#include <fstream>

class DFILE : public DOBJ { 

	public:

		DFILE();
		~DFILE();
		void setPath(std::string p); 
		void setName(std::string n); 
		void open(char rw); 
		void write(std::string msg); 
		void read(); 
		void close(); 

	private: 

		std::string path;
		std::string fname;		
		std::fstream file; 
}; 

#endif
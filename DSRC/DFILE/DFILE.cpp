//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DFILE__
#include "DFILE.h"
#endif

DFILE::DFILE() { 
	setPath("./DSRC/DFILE/DTEXTFILES/");
	setName("demo.txt");
}

DFILE::~DFILE() { 

}

void DFILE::setPath(std::string p) { 
	path = p; 
}

void DFILE::setName(std::string n) { 
	fname = n; 
}

void DFILE::open(char rw) {

	if(rw == 'r') { 
		file.open((path+fname).c_str(), std::fstream::in); 
	} else if(rw == 'w') { 
		file.open((path+fname).c_str(), std::fstream::out | std::fstream::app); 
	} else if(rw == 'x') { 
		file.open((path+fname).c_str(), std::fstream::out); 
	}

	if(!file.is_open()) { 
		std::cout << "Error, open function couldn't open file.\n"; 
	}

}

void DFILE::write(std::string msg) { 
	file.seekg (0, std::ios::end);
	file << msg.c_str(); 
}

void DFILE::read() { 
	std::string line; 
	if (file.is_open()) {
		file.clear();
		file.seekg (0, std::ios::beg);
		while ( ! file.eof() ) {
			getline (file,line);
			std::cout << line << "\n" << std::flush;
		}
	} else { 
		std::cout << "Error, read couldn't open file.\n"; 
	}
}

void DFILE::close() { 
	file.close();
}
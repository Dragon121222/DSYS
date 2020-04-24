//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DKINECT__
#include "DKINECT.h"
#endif

#include <iostream> 
#include <stdio.h>
#include <arrayfire.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <dirent.h>
#include <math.h>
#include <gtk/gtk.h>
#include <GL/glut.h>
#include <gmodule.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <bitset>

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/graphviz.hpp>

#include "/run/media/drake/Seagate Expansion Drive/BackupDesktop/Code/DSYS/DRIVERS/KINECTDRIVERS/libfreenect/wrappers/cpp/libfreenect.hpp"

DKINECT::DKINECT() { 

}

DKINECT::~DKINECT() { 

}

void DKINECT::vecToChr(std::vector<uint8_t> vec, char * c) { 
	uint8_t * d = vec.data(); 
	int s = vec.size(); 
	for(int i = 0; i < s; ++i ) { 
		c[i] = (char)d[i];
	}
}  

std::vector<uint8_t> DKINECT::chrToVec(const char * chr) { 
	return std::vector<uint8_t>(); 
}

void DKINECT::vecToChrTest() { 

	std::vector<uint8_t> vec; 

	for(uint8_t i = 0; i < 255; ++i) { 
		std::bitset<8> x(i);
		std::cout << ": " << x  << " : " <<(unsigned int)i << "\n"; 
		vec.push_back(i); 
	}

	std::cout << "\n\n"; 

	char msg[vec.size()]; 
	vecToChr(vec,msg); 
	const char * cmsg = (const char *)msg; 	

	for(int i = 0; i < 255; ++i) { 
		std::bitset<8> x(cmsg[i]);
		std::cout << ": " << x  << " : " <<(unsigned int)cmsg[i] << " : " << i << "\n"; 
	}

}


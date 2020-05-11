//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DML__
#include "DML.h"
#endif

#include <vector>
#include <iostream> 
#include <stdio.h>
#include <arrayfire.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <dirent.h>
#include <math.h>
#include <gmodule.h>

DML::DML() { 

} 

DML::~DML() { 

}

void DML::appendOp(DOP op, std::string name, int inputDim, int outputDim) { 	

	DOPList.push_back(op); 
	DNameList.push_back(name); 
	DInputDimList.push_back(inputDim); 
	DOutputDimList.push_back(outputDim); 

	if(name == "add") { 
		DKernel.push_back(af::randu(inputDim));
	} else { 
		std::cout << "Error, operator not recognized.\n"; 
	}

}

void DML::fire(af::array& input, af::array& output) { 
	af::array tmp = input; 
	auto ker = DKernel.begin(); 
	for(auto it = DOPList.begin(); it != DOPList.end(); ++it) { 
		(*it)(tmp,tmp,(*ker));
		++ker;  
	}
	output = tmp; 
} 

void DML::debugMachine() { 
	auto inDim = DInputDimList.begin(); 
	auto outDim = DOutputDimList.begin(); 
	auto ker = DKernel.begin(); 	
	int layer = 0; 
	std::string tag; 
	for(auto it = DNameList.begin(); it != DNameList.end(); ++it) { 
		std::cout << "*************************************************\n"
			 << "Operator Name:  " << (*it) << "\n"
			 << "Input Dimsion:  " << (*inDim) << "\n"
			 << "Output Dimsion: " << (*outDim) << "\n";
		tag = "Kernel Layer " + std::to_string(layer); 
		af::print(tag.c_str(),(*ker)); 
		++layer; 
		++inDim; 
		++outDim; 
		++ker; 
 	}
}

void DML::debugMachine(int index) { 

}


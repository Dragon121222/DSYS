//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DSFTGEN__
#include "DSFTGEN.h"
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
#include <algorithm>

//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************

DSFTGEN::DSFTGEN() { 

}

DSFTGEN::~DSFTGEN() { 

}

std::vector<std::string> DSFTGEN::writeClassHeaderFile() { 

	std::vector<std::string> Data; 

	std::string header = "class " + className; 

	if(polymorphism) { 

		header = header + " : "; 

		auto it1 = inheritance_relation.begin();
		auto it2 = relation.begin();

		while(true) { 

			header = header + (*it1) + std::string(" ") + (*it2);

			++it1;
			++it2;

			if(it1 != inheritance_relation.end()) { 
				header = header _ " , "; 
			} else { 
				break; 
			}

		} 

		header = header + " {";

	}

	Data.push_back(header); 

	//Add public functions and public variables

	Data.push_back(std::string("public:")); 	

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Gotta get the stuff out of it1. 
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	for(auto it1 = publicFunctionList.begin();it3 != publicFunctionList.end();++it3) { 

		std::string funcDec = (*it1).getOutputType() + std::string(" ") + (*it1).getFuncName() + std::string("("); 

		auto it2 = inputTypes.begin();
		auto it3 = inputNames.begin();

		std::string inputParameters; 

		while(true) { 

			inputParameters += (*it2) + std::string(" ") + (*it3); 

			++it2;
			++it3;

			if(it2 != inputTypes.end()) { 
				inputParameters += std::string(" ");
			} else { 
				break; 
			}

		} 

		auto it4 = publicVarTypes.begin();
		auto it5 = publicVarNames.begin();

		while(true) { 

			publicVariable += (*it4) + std::string(" ") + (*it5) + std::string(";"); 
			Data.push_back( publicVariable );

			++it4;
			++it5;

			if(it4 != publicVarTypes.end()) { 

			} else { 
				break; 
			}

		} 


	}
	
	//Add private functions and private variables


	Data.push_back("}"); 	

	return Data; 

}

void DSFTGEN::readClass(std::vector<std::string> t) { 

}

//****************************************************************************************************************
//****************************************************************************************************************
//****************************************************************************************************************

DFUNCGEN::DFUNCGEN() { 

}

DFUNCGEN::~DFUNCGEN() { 

}

std::vector<std::string> DFUNCGEN::writeFunction() { 

}

void DFUNCGEN::readFunction(std::vector<std::string> t) { 

}

void DFUNCGEN::setFuncName(std::string &t) { 

}

void DFUNCGEN::appendFuncDef(std::string &t) { 

}

void DFUNCGEN::appendFuncInput(std::string &type, std::string &name) { 

}

void DFUNCGEN::appendLocalVar(std::string &type, std::string &name) { 

}

void DFUNCGEN::setOutputVar(std::string &type, std::string &name) { 

}


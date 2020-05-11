
//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************


#ifndef __DML__
#define __DML__

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
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

class DML : public DOBJ { 

	typedef void (*DOP)(af::array &, af::array &, af::array &);

	public: 

		DML(); 
		~DML(); 

		void appendOp(DOP op, std::string name, int inputDim, int outputDim); 
		void fire(af::array& input, af::array& output); 
		void debugMachine(); 
		void debugMachine(int index); 		

	private: 

		std::vector<DOP> DOPList; 
		std::vector<std::string> DNameList;
		std::vector<int> DInputDimList; 
		std::vector<int> DOutputDimList; 		

		std::vector<af::array> DKernel; 

};

void add(af::array & input, af::array & output, af::array & kernel); 

#endif
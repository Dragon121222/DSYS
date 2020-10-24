//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************


#ifndef __DSFTGEN__
#define __DSFTGEN__

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


class DSFTGEN : public DOBJ { 

	public: 

		 DSFTGEN();
		~DSFTGEN(); 

		std::vector<std::string> writeClass(); 
		void readClass(std::vector<std::string> t); 

	private: 

		std::string className; 
		std::vector<DFUNCGEN> publicFunctionList; 
		std::vector<DFUNCGEN> privateFunctionList; 

		std::vector<std::string> publicVarTypes;
		std::vector<std::string> publicVarNames;

		std::vector<std::string> privateVarTypes;
		std::vector<std::string> privateVarNames;

		std::vector<std::string> inheritance_relation; 
		std::vector<std::string> relation;

};

//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

class DFUNCGEN : public DOBJ {

	public:

		 DFUNCGEN();
		~DFUNCGEN();

		std::vector<std::string> writeFunction();
		void readFunction(std::vector<std::string> t);

		void setFuncName(std::string &t);
		void appendFuncDef(std::string &t);
		void appendFuncInput(std::string &type, std::string &name);
		void appendLocalVar(std::string &type, std::string &name);
		void setOutputVar(std::string &type, std::string &name);

		std::vector<std::string> getInputTypes(); 
		std::vector<std::string> getInputNames(); 

		std::string getFuncName(); 
		std::string getOutputType(); 

	private: 

		std::string funcName; 
		std::vector<std::string> funcDef; 

		std::vector<std::string> inputTypes;
		std::vector<std::string> inputNames;

		std::vector<std::string> localVarTypes;
		std::vector<std::string> localVarNames;

		std::string outputType;
		std::string outputName;



}

#endif
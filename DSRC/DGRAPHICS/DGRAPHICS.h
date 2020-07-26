
//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************


#ifndef __DGRAPHICS__
#define __DGRAPHICS__

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

class DGRAPHICS : public DOBJ { 

	public: 

		//Constructor and Deconstructor
		DGRAPHICS(); 
		~DGRAPHICS(); 

		// Functions
		void topDownGrad(af::array &IO);
		void topDownSin(af::array &IO, float lambda = 1);
		void sinOpp(af::array &IO,float lambda = 1,float bias = 0); 
		void ball2D(af::array &IO); 

		// Graphics Unit Tests
		void topDownGradTest(); 
		void topDownSinTest(); 
		void centralWaveGradTest(); 

		// Diagnostics Unit Tests
		void vectorAnalysisTest(); 

		// Diagnostics
		void vectorAnalysis(af::array &I, std::string name = "Default"); 
		std::string Type(af::array &I); 
		
	private: 


};


#endif
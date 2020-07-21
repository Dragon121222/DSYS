
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

		DGRAPHICS(); 
		~DGRAPHICS(); 

		// Functions

		void topDownGrad(af::array &I, af::array &O);

		// Unit Tests

		void topDownGradTest(); 

	private: 


};


#endif
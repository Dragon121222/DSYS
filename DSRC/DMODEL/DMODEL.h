//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DMODEL__
#define __DMODEL__
#endif

#include <arrayfire.h>
#include <vector>

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
#endif

class DMODEL : public DOBJ { 

	public: 
		 //=========================================================================================================================
		 // Constructors / Deconstructors
		 //=========================================================================================================================
		 DMODEL(); 
		~DMODEL(); 


	private: 

		std::vector<af::array> vertices; 

}; 

void startModelManager(); 

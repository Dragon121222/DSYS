
//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************


#ifndef __DTALK__
#define __DTALK__

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
#endif

#ifndef __DFILE__
#include "../DFILE/DFILE.h"
#endif

#include <string>
#include <stdlib.h>

class DTALK : public DOBJ { 

	public:

		DTALK();
		~DTALK();

		void say(std::string text); 

		void setPath(std::string p); 
		void setName(std::string fname); 

	private: 

		std::string path; 
		std::string fname; 

		DFILE * DF; 

}; 

#endif
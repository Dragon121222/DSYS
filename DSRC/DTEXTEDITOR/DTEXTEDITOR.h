//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DTEXTEDITOR__
#define __DTEXTEDITOR__
#endif

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
#endif

#ifndef __DGTKWIDOW__
#include "../DGTKWINDOW/DGTKWINDOW.h"
#endif

class DTEXTEDITOR : public DOBJ { 

	public: 
		 //=========================================================================================================================
		 // Constructors / Deconstructors
		 //=========================================================================================================================
		 DTEXTEDITOR(); 
		~DTEXTEDITOR(); 

		void startGUI(); 

	private: 

};

void startDTEXTEDITOR(); 

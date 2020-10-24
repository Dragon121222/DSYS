//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DMODELMANAGER__
#define __DMODELMANAGER__
#endif

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
#endif

#ifndef __DMODEL__
#include "../DMODEL/DMODEL.h"
#endif

class DMODELMANAGER : public DOBJ { 

	public: 
		 //=========================================================================================================================
		 // Constructors / Deconstructors
		 //=========================================================================================================================
		 DMODELMANAGER(); 
		~DMODELMANAGER(); 

		void startGUI(); 

		void openCVSModel(std::string path, DMODEL & model);

		void saveCVSModel(std::string path, DMODEL & model); 

		void addModel(DMODEL & model);

		void createSphere(DMODEL & model, double radius);

		void createTorus(DMODEL & model, double radius_0, double radius_1);

		void createCuboid(DMODEL & model, double length_0, double length_1);

		void createCone(DMODEL & model, double height, double radius); 		



	private: 

		std::vector<DMODEL> modelList;  
		int resolution; 

};

void startModelManager(); 

#ifndef __DMODELMANAGER__
#include "DMODELMANAGER.h"
#endif

DMODELMANAGER::DMODELMANAGER() { 

}

DMODELMANAGER::~DMODELMANAGER() { 

}

void DMODELMANAGER::openCVSModel(std::string path, DMODEL & model) { 

}

void DMODELMANAGER::saveCVSModel(std::string path, DMODEL & model) { 

}

void DMODELMANAGER::addModel(DMODEL & model) { 

}

void DMODELMANAGER::createSphere(DMODEL & model, double radius) { 

}

void DMODELMANAGER::createTorus(DMODEL & model, double radius_0, double radius_1) { 

}

void DMODELMANAGER::createCuboid(DMODEL & model, double length_0, double length_1) { 

}

void DMODELMANAGER::createCone(DMODEL & model, double height, double radius) { 

}

void DMODELMANAGER::startGUI() { 
	startModelManager(); 
} 
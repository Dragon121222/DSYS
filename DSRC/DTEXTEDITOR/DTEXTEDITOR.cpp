#ifndef __DTEXTEDITOR__
#include "DTEXTEDITOR.h"
#endif

DTEXTEDITOR::DTEXTEDITOR() { 

}

DTEXTEDITOR::~DTEXTEDITOR() { 

}

void DTEXTEDITOR::startGUI() { 
	DGTKWINDOW * dwindow = new DGTKWINDOW(); 

	dwindow->defaultBuilder(); 

	dwindow->addWidget("Open File","button_with_label",0,0,&_sayHello,"clicked"); 
	dwindow->addWidget("Save File","button_with_label",1,0,&_sayHello,"clicked"); 
	dwindow->addWidget("New File" ,"button_with_label",2,0,&_sayHello,"clicked"); 

	dwindow->constructWindow(); 

	dwindow->defaultDisplay(); 

	delete(dwindow); 
} 
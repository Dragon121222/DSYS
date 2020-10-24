//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DMODELMANAGER__
#include "DMODELMANAGER.h"
#endif

#ifndef __DGTKWIDOW__
#include "../DGTKWINDOW/DGTKWINDOW.h"
#endif

void _sayHello(GtkButton * widget, gpointer ptr);

void startModelManager() { 

	DGTKWINDOW * dwindow = new DGTKWINDOW(); 

	dwindow->defaultBuilder(); 

	dwindow->addWidget("Open Model","button_with_label",0,0,&_sayHello,"clicked"); 
	dwindow->addWidget("Save Model","button_with_label",1,0,&_sayHello,"clicked"); 
	dwindow->addWidget("New Model" ,"button_with_label",2,0,&_sayHello,"clicked"); 

	dwindow->constructWindow(); 

	dwindow->defaultDisplay(); 

	delete(dwindow); 

}


// Callbacks
void _sayHello(GtkButton * widget, gpointer ptr) { 
	std::cout << "Hello world\n"; 
	std::cout << gtk_button_get_label( GTK_BUTTON(widget) ) << "\n"; 
	std::cout << "This: " << ((DGTKWINDOW*)ptr)->getTitle() << "\n"; 
}

//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DGTKWINDOW__
#include "DGTKWINDOW.h"
#endif

#include <iostream> 
#include <stdio.h>
#include <arrayfire.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <dirent.h>
#include <math.h>
#include <gtk/gtk.h>
#include <GL/glut.h>
#include <gmodule.h>
#include <sys/socket.h> 
#include <netinet/in.h> 

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/graphviz.hpp>

// Callback method prototypes
void sayHello(GtkButton * widget, gpointer ptr); 

// Constructors / Deconstructors
DGTKWINDOW::DGTKWINDOW() { 
	std::cout << "\tDGTKWINDOW ACTIVE\n"; 
	title = "DGTKWINDOW"; 
}

DGTKWINDOW::~DGTKWINDOW() { 

}

// Builders
void DGTKWINDOW::defaultBuilder() { 
	
	std::cout << "\t\tCalling Default Builder\n"; 

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	grid = gtk_grid_new ();

	gtk_container_add (GTK_CONTAINER (window), grid);

	gtk_window_set_title (GTK_WINDOW (window), title.c_str());

}

void DGTKWINDOW::constructWindow() { 

	std::cout << "\t\tCalling Construct Window\n"; 

	auto widgetListIterator = widgetList.begin(); 
	auto widgetTypeListIterator = widgetTypeList.begin(); 
	auto widgetRowListIterator = widgetRowList.begin(); 
	auto widgetColListIterator = widgetColList.begin(); 

	auto callbackListIterator = callbackList.begin(); 
	auto callbackTypeListIterator = callbackTypeList.begin(); 

	auto textBufferListIterator = textBufferList.begin(); 

	while(widgetListIterator != widgetList.end()) { 

		if( (*widgetTypeListIterator) == "button_with_label" ) { 

			g_signal_connect( GTK_BUTTON(*widgetListIterator) , (*callbackTypeListIterator).c_str() , G_CALLBACK( (*callbackListIterator) ) , this ); 

			gtk_grid_attach (GTK_GRID (grid), (GtkWidget*)(*widgetListIterator), (*widgetColListIterator) , (*widgetRowListIterator), 1, 1);

			widgetListIterator++; 
			widgetTypeListIterator++; 
			widgetRowListIterator++; 
			widgetColListIterator++; 

			callbackListIterator++; 
			callbackTypeListIterator++; 

		} else if( (*widgetTypeListIterator) == "non-empty_text_field") { 

			gtk_grid_attach (GTK_GRID (grid), (GtkWidget*)(*widgetListIterator), (*widgetColListIterator) , (*widgetRowListIterator), 1, 1);

			widgetListIterator++; 
			widgetTypeListIterator++; 
			widgetRowListIterator++; 
			widgetColListIterator++; 

			textBufferListIterator++; 

		} else if( (*widgetTypeListIterator) == "combo_box") { 

			gtk_grid_attach (GTK_GRID (grid), (GtkWidget*)(*widgetListIterator), (*widgetColListIterator) , (*widgetRowListIterator), 1, 1);

			widgetListIterator++; 
			widgetTypeListIterator++; 
			widgetRowListIterator++; 
			widgetColListIterator++; 

		} else { 
			std::cout << "Widget Type Not Identified\n"; 
		}

	}

}

void DGTKWINDOW::demoWindow() { 

	std::cout << "\t\tCalling Demo Window\n"; 

	addWidget("Push Me 1!","button_with_label",0,0,&sayHello,"clicked"); 
	addWidget("Enter Text Here 1!", "non-empty_text_field", 0,1); 

	addWidget("Push Me 2!","button_with_label",1,0,&sayHello,"clicked"); 
	addWidget("Enter Text Here 2!", "non-empty_text_field", 1,1); 

	addWidget("Push Me 3!","button_with_label",2,0,&sayHello,"clicked"); 
	addWidget("Enter Text Here 3!", "non-empty_text_field", 2,1); 

	addWidget("Push Me 4!","button_with_label",3,0,&sayHello,"clicked"); 
	addWidget("Enter Text Here 4!", "non-empty_text_field", 3,1); 

	addWidget("Push Me 5!","button_with_label",4,0,&sayHello,"clicked"); 

	std::vector<std::string> opts; 
	opts.push_back("Option 1"); 
	opts.push_back("Option 2");
	opts.push_back("Option 3");  	
	addWidget(opts, "combo_box", 4,1); 

}

// Display Command
void DGTKWINDOW::defaultDisplay() { 

	std::cout << "\t\tCalling Default Display\n"; 

	gtk_widget_show_all (window);

}

// Set methods
void DGTKWINDOW::setTitle(std::string t) { 
	title = t; 
}

// Get methods
std::string DGTKWINDOW::getTitle() { 
	return title; 
}

// Callbacks
void sayHello(GtkButton * widget, gpointer ptr) { 
	std::cout << "Hello world\n"; 
	std::cout << gtk_button_get_label( GTK_BUTTON(widget) ) << "\n"; 
	std::cout << "This: " << ((DGTKWINDOW*)ptr)->getTitle() << "\n"; 
}

// Generator methods
void DGTKWINDOW::addWidget(std::string title, std::string type, int row, int col, fptr callback, std::string callbackType) { 

	std::cout << "\t\tCalling Add Widget(Button Version)\n"; 

	widgetList.push_back( gtk_button_new_with_label ( (title).c_str() )  ); 
	widgetTypeList.push_back(type); 
	widgetRowList.push_back(row); 
	widgetColList.push_back(col); 

	callbackList.push_back(callback); 
	callbackTypeList.push_back(callbackType); 

}

void DGTKWINDOW::addWidget(std::string title, std::string type, int row, int col) { 

	std::cout << "\t\tCalling Add Widget(Text Version)\n"; 

	textBufferList.push_back( gtk_entry_buffer_new( (title).c_str() , defaultBufferSize ) ); 
	widgetList.push_back(gtk_entry_new_with_buffer( *(textBufferList.end() - 1) ) ); 

	widgetTypeList.push_back(type); 
	widgetRowList.push_back(row); 
	widgetColList.push_back(col); 

}

void DGTKWINDOW::addWidget(std::vector<std::string> options, std::string type, int row, int col) { 

	std::cout << "\t\tCalling Add Widget(Combo Box Version)\n"; 
 
	widgetList.push_back( gtk_combo_box_text_new () ); 

	for(auto it = options.begin(); it != options.end(); ++it) { 
	  	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT ( *(widgetList.end()-1) ), (*it).c_str());
	}

	gtk_combo_box_set_active (GTK_COMBO_BOX ( *(widgetList.end()-1) ), 0);

	widgetTypeList.push_back(type); 
	widgetRowList.push_back(row); 
	widgetColList.push_back(col); 

}




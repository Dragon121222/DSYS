//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DGTKWINDOW__
#define __DGTKWINDOW__

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
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

class DGTKWINDOW : public DOBJ { 

	typedef void (*fptr)(GtkButton *, gpointer);

	public: 
		 // Constructors / Deconstructors
		 DGTKWINDOW(); 
		~DGTKWINDOW(); 

		// Builder methods
		void defaultBuilder(); 
		void constructWindow(); 
		void demoWindow(); 

		// Display methods
		void defaultDisplay(); 

		// Set methods
		void setTitle(std::string t); 

		// Get methods
		std::string getTitle();

		// Generator methods
		void addWidget(std::string title, std::string type, int row, int col, fptr callback, std::string callbackType); 
		void addWidget(std::string title, std::string type, int row, int col); 
		void addWidget(std::vector<std::string> options, std::string type, int row, int col); 


	private: 

		std::string title; 

		GtkWidget* window; 
		GtkWidget* grid; 

		// Common properties
		std::vector<GtkWidget*> widgetList;
		std::vector<std::string> widgetTypeList; 
		std::vector<int> widgetRowList; 
		std::vector<int> widgetColList; 

		// Button specific properties
		std::vector<fptr> callbackList; 
		std::vector<std::string> callbackTypeList; 

		// Text field specific properties
		std::vector<GtkEntryBuffer*> textBufferList; 
		int defaultBufferSize = 255; 

}; 



#endif
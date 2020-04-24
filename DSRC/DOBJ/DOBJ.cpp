//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

#ifndef __DOBJ__
#include "DOBJ.h"
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


DOBJ::DOBJ() { 
	std::cout << "DOBJ ACTIVE\n"; 
}

DOBJ::~DOBJ() { 

}

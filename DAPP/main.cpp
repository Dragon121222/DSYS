//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************

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
#include "/run/media/drake/Seagate Expansion Drive/BackupDesktop/Code/DSYS/DRIVERS/KINECTDRIVERS/libfreenect/wrappers/cpp/libfreenect.hpp"

#ifndef __DOBJ__
#include "../DSRC/DOBJ/DOBJ.h"
#endif

#ifndef __DGTKWIDOW__
#include "../DSRC/DGTKWINDOW/DGTKWINDOW.h"
#endif

#ifndef __DGLUTWINDOW__
#include "../DSRC/DGLUTWINDOW/DGLUTWINDOW.h"
#endif

#ifndef __DKINECT__
#include "../DSRC/DKINECT/DKINECT.h"
#endif

#ifndef __DNETWORK__
#include "../DSRC/DNETWORK/DNETWORK.h"
#endif

#ifndef __DSERVERTCP__
#include "../DSRC/DSERVERTCP/DSERVERTCP.h"
#endif

#ifndef __DCLIENTTCP__
#include "../DSRC/DCLIENTTCP/DCLIENTTCP.h"
#endif

#ifndef __DSERVERUDP__
#include "../DSRC/DSERVERUDP/DSERVERUDP.h"
#endif

#ifndef __DCLIENTUDP__
#include "../DSRC/DCLIENTUDP/DCLIENTUDP.h"
#endif

int argcCOPY;
char** argvCOPY; 

void DGLUTDEMO(GtkButton * widget, gpointer ptr) { 

	globalObj->initGlut(argcCOPY,argvCOPY);
	globalObj->demoMainLoop(); 
	delete(globalObj); 

}

void DGTKDEMO(GtkButton * widget, gpointer ptr) { 

	DGTKWINDOW * dwindow = new DGTKWINDOW(); 

	dwindow->defaultBuilder(); 
	dwindow->demoWindow(); 
	dwindow->constructWindow(); 

	dwindow->defaultDisplay(); 

	delete(dwindow); 

}

Freenect::Freenect freenect;
MyFreenectDevice* device;

void demoDrawGLScene() {

    static std::vector<uint8_t> rgb(640*480*3);
    static std::vector<uint16_t> depth(640*480);

    device->getRGB(rgb);
    device->getDepth(depth);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPointSize(1.0f);

    glBegin(GL_POINTS);

    if (!color) {
    	glColor3ub(255, 255, 255);
    }

    for (int i = 0; i < 480*640; ++i) {   
        if (color) {
            glColor3ub( rgb[3*i+0],    // R
                        rgb[3*i+1],    // G
                        rgb[3*i+2] );  // B
        }

        float f = 595.f;
        // Convert from image plane coordinates to world coordinates
        glVertex3f( (i%640 - (640-1)/2.f) * depth[i] / f,  // X = (x - cx) * d / fx
                    (i/640 - (480-1)/2.f) * depth[i] / f,  // Y = (y - cy) * d / fy
                    depth[i] );                            // Z = d
    }

    glEnd();
    
    // Draw the world coordinate frame
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);  // X-axis
    glVertex3f(  0, 0, 0);
    glVertex3f( 50, 0, 0);
    glColor3ub(0, 255, 0);  // Y-axis
    glVertex3f(0,   0, 0);
    glVertex3f(0,  50, 0);
    glColor3ub(0, 0, 255);  // Z-axis
    glVertex3f(0, 0,   0);
    glVertex3f(0, 0,  50);
    glEnd();

    // Place the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(zoom, zoom, 1);
    gluLookAt( -7*anglex, -7*angley, -1000.0,
                     0.0,       0.0,  2000.0,
                     0.0,      -1.0,     0.0 );

    glutSwapBuffers();

}

void demokeyPressed(unsigned char key, int x, int y) {

    switch (key) {
        case  'C':
        case  'c':
            color = !color;
            break;

        case  'Q':
        case  'q':
        case 0x1B:  // ESC
            glutDestroyWindow(window);
            device->stopDepth();
            device->stopVideo();
            exit(0);
    }

}

void DKINECT_UNIT_TESTS(GtkButton * widget, gpointer ptr) {

    DKINECT * obj = new DKINECT(); 

    obj->vecToChrTest(); 

    delete(obj); 

} 

void DKINECT_DEMO(GtkButton * widget, gpointer ptr) {

    device = &freenect.createDevice<MyFreenectDevice>(0);
    device->startVideo();
    device->startDepth();
    
    glutInit(&argcCOPY, argvCOPY);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);

    window = glutCreateWindow("LibFreenect");
    glClearColor(0.45f, 0.45f, 0.45f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0f);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(50.0, 1.0, 900.0, 11000.0);
        
    glutDisplayFunc(&demoDrawGLScene);
    glutIdleFunc(&idleGLScene);
    glutReshapeFunc(&resizeGLScene);
    glutKeyboardFunc(&demokeyPressed);
    glutMotionFunc(&mouseMoved);
    glutMouseFunc(&mouseButtonPressed);

    printInfo();

    glutMainLoop();

}

/*

void DKINECT_NETWORK_STREAM(GtkButton * widget, gpointer ptr) { 

    static std::vector<uint8_t> mark(640);
    for(int i = 0; i < 640; i++) { 
        mark.at(i) = 0; 
    }

    device = &freenect.createDevice<MyFreenectDevice>(0);

    DKINECT * c = new DKINECT(); 
    DCLIENTTCP * client = new DCLIENTTCP(); 
    client->setPortNumber(4444);
    client->openSocket(AF_INET, SOCK_STREAM, 0); 
    client->getServer("192.168.0.2"); 
    client->populateSocketStruct(AF_INET);

    device->startVideo();
    device->startDepth();

    static std::vector<uint8_t> rgb(640*480*3);
    static std::vector<uint16_t> depth(640*480);

    for(int i = 0; i < 5; i++) { 
        device->getRGB(rgb);
        device->getDepth(depth);

        for(int i = 0; i < 10; i++) { 
            std::cout << (unsigned int)rgb.at(i) << " ";             
        }

        std::cout << "\n" << std::flush; 
    }

    if(0 < rgb.at(50)) { 
        std::cout << "Starting stream\n";  
        client->connectToServer(); 
        while(1) { 
            device->getRGB(rgb);
            device->getDepth(depth);
            rgb.at(0) = (uint8_t)0; 
            rgb.at(1) = (uint8_t)0; 
            rgb.at(2) = (uint8_t)0; 
            client->send_Msg( rgb.data(), 384000 ); 
        }

    }



    delete(client); 

}

*/

void DCLIENTTCP_DSERVERTCP_DEMO(GtkButton * widget, gpointer ptr) {
 
	std::cout << "Enter s to launch server, c to launch client\n"; 
	char x; 
	std::cin >> x; 

	if(x == 'c') { 
		DCLIENTTCP * client = new DCLIENTTCP(); 
		client->demo(); 
		delete(client); 
	} else if(x == 's') { 
		DSERVERTCP * server = new DSERVERTCP(); 
		server->demo(); 
		delete(server); 
	} else { 
		std::cout << "Error\n"; 
	}

}

void DCLIENTUDP_DSERVERUDP_DEMO(GtkButton * widget, gpointer ptr) {
 
    std::cout << "Enter s to launch server, c to launch client\n"; 
    char x; 
    std::cin >> x; 

    if(x == 'c') { 
        DCLIENTUDP * client = new DCLIENTUDP(); 
        client->demo(); 
        delete(client); 
    } else if(x == 's') { 
        DSERVERUDP * server = new DSERVERUDP(); 
        server->demo(); 
        delete(server); 
    } else { 
        std::cout << "Error\n"; 
    }

}

/*
void DCLIENTTCP_UNITY_CONNECT(GtkButton * widget, gpointer ptr) { 

	DCLIENTTCP * client = new DCLIENTTCP(); 
	client->unityClientExample(); 
	delete(client); 

}
*/

// Callback method prototypes
void defaultCallback(GtkButton * widget, gpointer ptr); 


#define __DAPP_MANAGER_SYSTEM__	
#ifdef __DAPP_MANAGER_SYSTEM__	
int main(int argc,  char** argv) { 

	argcCOPY = argc;
	argvCOPY = argv; 

	gtk_init (&argc, &argv);

	DGTKWINDOW * dwindow = new DGTKWINDOW(); 

	dwindow->defaultBuilder(); 

	std::cout << "\t\tCalling Demo Window\n"; 


//	dwindow->addWidget("DCLIENTTCP_UNITY_CONNECT","button_with_label",0,0,&DCLIENTTCP_UNITY_CONNECT,"clicked"); 
    dwindow->addWidget("DCLIENTUDP_DSERVERUDP_DEMO","button_with_label",0,0,&DCLIENTUDP_DSERVERUDP_DEMO,"clicked"); 
	dwindow->addWidget("DCLIENTTCP_DSERVERTCP_DEMO","button_with_label",1,0,&DCLIENTTCP_DSERVERTCP_DEMO,"clicked"); 
	dwindow->addWidget("DGTKDEMO","button_with_label",2,0,&DGTKDEMO,"clicked"); 
	dwindow->addWidget("DGLUTDEMO","button_with_label",3,0,&DGLUTDEMO,"clicked"); 
	dwindow->addWidget("DKINECT_DEMO","button_with_label",4,0,&DKINECT_DEMO,"clicked"); 
//    dwindow->addWidget("DKINECT_NETWORK_STREAM","button_with_label",5,0,&DKINECT_NETWORK_STREAM,"clicked"); 
    dwindow->addWidget("DKINECT_UNIT_TESTS","button_with_label",6,0,&DKINECT_UNIT_TESTS,"clicked");     

	dwindow->constructWindow(); 

	dwindow->defaultDisplay(); 

	gtk_main();

	delete(dwindow); 

	return 0;
}
#endif

// Callbacks
void defaultCallback(GtkButton * widget, gpointer ptr) { 
	std::cout << "Hello world\n"; 
	std::cout << gtk_button_get_label( GTK_BUTTON(widget) ) << "\n"; 
	std::cout << "This: " << ((DGTKWINDOW*)ptr)->getTitle() << "\n"; 
}

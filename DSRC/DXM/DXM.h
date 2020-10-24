//****************************************************************************************************************
// Written By Daniel Drake 
//****************************************************************************************************************


#ifndef __DXM__
#define __DXM__

#ifndef __DOBJ__
#include "../DOBJ/DOBJ.h"
#endif

#include <vector>
#include <iostream> 
#include <stdio.h>
#include <arrayfire.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <dirent.h>
#include <math.h>
#include <gmodule.h>


extern "C" {
#include <X11/Xlib.h>
}
#include <memory>
#include <mutex>
#include <string>

using std::unique_ptr;

class DXM : public DOBJ { 

	public:
	// Factory method for establishing a connection to an X server and creating a
	// WindowManager instance.
	static ::std::unique_ptr<DXM> Create();
	// Disconnects from the X server.
	~DXM();
	// The entry point to this class. Enters the main event loop.
	void Run();

	private:
	// Invoked internally by Create().
	DXM(Display* display);

	// Handle to the underlying Xlib Display struct.
	Display* display_;

	// Handle to root window.
	Window root_;

	// Xlib error handler. It must be static as its address is passed to Xlib.
	static int OnXError(Display* display, XErrorEvent* e);

	// Xlib error handler used to determine whether another window manager is
	// running. It is set as the error handler right before selecting substructure
	// redirection mask on the root window, so it is invoked if and only if
	// another window manager is running. It must be static as its address is
	// passed to Xlib.
//	static int OnWMDetected(Display* display, XErrorEvent* e);

	// Whether an existing window manager has been detected. Set by OnWMDetected,
	// and hence must be static.
//	static bool wm_detected_;

};

#endif
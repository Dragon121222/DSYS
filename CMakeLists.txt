cmake_minimum_required(VERSION 3.8.2)
project(DLRGSFTSYS)
set(CMAKE_CXX_STANDARD 17)

#DKINECT STUFF
set(THREADS_USE_PTHREADS_WIN32 true)
find_package(Threads)
include_directories(${THREADS_PTHREADS_INCLUDE_DIR})

find_path(LIBUSB_INCLUDE_DIR NAMES libusb.h PATH_SUFFIXES "include" "libusb" "libusb-1.0")
find_library(LIBUSB_LIBRARY NAMES usb PATH_SUFFIXES "lib" "lib32" "lib64")

find_package(libfreenect REQUIRED)
include_directories( ${libfreenect_INCLUDE_DIRS} )
include_directories( /run/media/drake/Seagate Expansion Drive/BackupDesktop/Code/DSYS/DRIVERS/KINECTDRIVERS/libfreenect/wrappers/cpp/ )
include_directories( /run/media/drake/Seagate Expansion Drive/BackupDesktop/Code/DSYS/DRIVERS/KINECTDRIVERS/libfreenect/include/ )

#Add arrayfire
find_package(ArrayFire REQUIRED)

#Add GTK3
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

#Add Boost Libraries 
find_package( Boost REQUIRED COMPONENTS program_options regex filesystem graph)
include_directories( ${Boost_INCLUDE_DIRS} )

#Add OpenGL Libraries
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${LIBUSB_INCLUDE_DIR})

add_executable(exe DSRC/DOBJ/DOBJ.h DSRC/DOBJ/DOBJ.cpp 
				   DSRC/DGTKWINDOW/DGTKWINDOW.h DSRC/DGTKWINDOW/DGTKWINDOW.cpp 
				   DSRC/DGLUTWINDOW/DGLUTWINDOW.h DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp 
				   DSRC/DKINECT/DKINECT.h DSRC/DKINECT/DKINECT.cpp  
				   DSRC/DNETWORK/DNETWORK.h DSRC/DNETWORK/DNETWORK.cpp 
				   DSRC/DSERVERTCP/DSERVERTCP.h DSRC/DSERVERTCP/DSERVERTCP.cpp 
				   DSRC/DCLIENTTCP/DCLIENTTCP.h DSRC/DCLIENTTCP/DCLIENTTCP.cpp 
				   DSRC/DSERVERUDP/DSERVERUDP.h DSRC/DSERVERUDP/DSERVERUDP.cpp 
				   DSRC/DCLIENTUDP/DCLIENTUDP.h DSRC/DCLIENTUDP/DCLIENTUDP.cpp 				   
				   DAPP/main.cpp )

target_link_libraries(exe  
					  ArrayFire::afcpu 
					  freenect 
					  ${GTK3_LIBRARIES} 
					  ${OPENGL_LIBRARIES} 
					  ${GLUT_LIBRARY} 
					  ${Boost_LIBRARIES} 
					  ${CMAKE_THREAD_LIBS_INIT} 
					  ${MATH_LIB} ${LIBUSB_LIBRARY} 
					  ${libfreenect_LIBRARIES} 
					  )






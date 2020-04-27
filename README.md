DSYS - Drake's System

This is my work in progress. 

There is some missing code, specifically the kinect driver stuff, but I didn't write that. 
I'll make a script to add it later. 

This is an OOP system. 
The DOBJ is the base class which all the other classes inherit from. 
It will hold the general purpose methods and variables. 

The DAPP holds the main functions and code to run various apps defined throughout the system. 
By organizing my code this way and not having indivaual projects per app, 
I have a centralized system and no need to rebuild stuff like the cmakelist files which would be unique to each project. 

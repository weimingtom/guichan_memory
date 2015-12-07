# guichan_memory
Drawing guichan to memory, and then drawing it to any display system or game framework.

## History:  
2015-12-06: drawhline and drawvline bug; mouse pos limit; glutPassiveMotionFunc pos transform.  
2015-11-14: Adding SDLMOD clip rect process, migrating to glut 3.7.6, fixing glut idle problem (CPU 100%).  
2015-11-08: Fixing memory leak (see glTexImage2D), glut input porting is OK now (see glut.hpp).  
2015-10-19: glut+sdlmod port, no input porting :).  

## References:  
* Guichan 0.8.2  
http://sourceforge.net/projects/guichan/  

* **SDLMOD** is my mod version of SDL 1.2.15  
http://libsdl.org/  

* GLUT 3.7  
https://www.opengl.org/resources/libraries/glut/  
https://www.opengl.org/resources/libraries/glut/glut_downloads.php  

* GLUT 3.7.6  
http://www.ece.lsu.edu/xinli/OpenGL/GLUTSetup.htm  

* POSIX Threads for Win32   
https://www.sourceware.org/pthreads-win32/  

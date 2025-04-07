#ifndef UTESTF_H
#define UTESTF_H

/* Check if the framework is included */
void utestf_chk(void);
/* Run a test and print a message depending if the teste passed or not.
	The first parameter is a pointer to the function that perform the test
	and should return 0 for success, otherwise 1. The second parameter
	specifies 1 to exit the program at fail, otherwise 0. The thrid
	parameter specifies the number of the test as a reference for the 
	programmer. */
void utestf_run(int (*testfun)(void), int eof, int tno);

#endif

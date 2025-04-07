#include <utestf.h>
#include <stdlib.h>
#include <stdio.h>

#define TESTSTR "Testing UTESTF Framework OK"
#define NULLFUN "Pointer to function NULL"
#define TESTFAIL "Test failed at test number:"
#define TESTSUCCESS "Test succeeded at test number:"

void utestf_chk(void)
{
	printf("%s\n", TESTSTR);
}

void utestf_run(int (*testfun)(void), int eof, int tno)
{
	if (!testfun) {
		printf("%s\n", NULLFUN);
		return;
	}
	if (testfun() != 0) {
		printf("%s %d\n", TESTFAIL, tno);
		if (eof)
			exit(EXIT_FAILURE);
		return;
	}
	printf("%s %d\n", TESTSUCCESS, tno);
}


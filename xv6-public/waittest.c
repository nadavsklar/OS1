#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	int exitcode;
	if (fork() == 0)
		exit(5);
	wait(&exitcode);
	printf(STDOUT, "Child exit code is: %d\n", exitcode);
	exit(0);
}
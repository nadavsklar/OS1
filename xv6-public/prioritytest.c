#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
	int i;
	int childpid = fork();
	int secchildpid;

	if (childpid == 0)
	{
		childpid = getpid();
		set_ps_priority(1);
		for (i = 0; i < 100; i++)
		{
			printf(STDOUT,"My pid is: %d priority: 1\n", childpid);
		}
		exit(0);
	}
	else
	{
		secchildpid = fork();
		if (secchildpid == 0)
		{
			childpid = getpid();
			set_ps_priority(5);
			for (i = 0; i < 100; i++)
			{
			printf(STDOUT,"My pid is: %d priority: 5\n", childpid);
			}
			exit(0);
		}
		else
		{
			childpid = getpid();
			set_ps_priority(10);
			for (i = 0; i < 100; i++)
			{
				printf(STDOUT,"My pid is: %d priority: 10\n", childpid);
			}
			wait(NULL);
			wait(NULL);
			exit(0);
		}
	}
}
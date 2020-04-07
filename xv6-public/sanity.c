#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
	int secchildpid;

	printf(STDOUT, "%s %s %s %s %s\n", "PID", "PS_PRIORITY", "STIME", "RETIME", "RTIME");
	int childpid = fork();

	if (childpid == 0)
	{
		int i = 1000000, dummy = 0;	
		struct perf p;	
		
		set_ps_priority(10);
		set_cfs_priority(3);
		
		while(i > 0)
		{
 			dummy += i;
 			i--;
		}
 		
 		proc_info(&p);
 		printf(STDOUT, "%d %d %d %d %d\n", getpid(), p.ps_priority, p.stime, p.retime, p.rtime);
		exit(0);
	}
	else
	{
		secchildpid = fork();
		if (secchildpid == 0)
		{
			int i = 1000000, dummy = 0;
			struct perf p;	
			
			set_ps_priority(5);
			set_cfs_priority(2);
			
			while(i > 0)
			{
	 			dummy += i;
	 			i--;
			}
 			
 			proc_info(&p);
 			printf(STDOUT, "%d %d %d %d %d\n", getpid(), p.ps_priority, p.stime, p.retime, p.rtime);
			exit(0);
		}
		else
		{
			int i = 1000000, dummy = 0;
			struct perf p;	
			
			set_ps_priority(1);
			set_cfs_priority(1);
			
			while(i > 0)
			{
	 			dummy += i;
	 			i--;
			}
 			
 			proc_info(&p);
			printf(STDOUT, "%d %d %d %d %d\n", getpid(), p.ps_priority, p.stime, p.retime, p.rtime);
			
			wait(NULL);
			wait(NULL);
			exit(0);
		}
	}
}
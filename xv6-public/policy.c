#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
	int new_policy;
	if (*argv[1] == '-')
		new_policy = -1;
	else 
	 	new_policy = atoi(argv[1]);
	policy(new_policy);

	switch (new_policy) 
	  {
	    case 0: 
		    printf(STDOUT,"Policy has been successfully changed to Default Policy\n");
		    break;
	    case 1:
		    printf(STDOUT,"Policy has been successfully changed to Priority Policy\n");
		    break;
	    case 2:
		    printf(STDOUT,"Policy has been successfully changed to CFS Policy\n");
		    break;
	    default:
	      	printf(STDOUT,"Error replacing policy, no such a policy number (%d)\n", new_policy);
			break;
	  }

  exit(0);
}
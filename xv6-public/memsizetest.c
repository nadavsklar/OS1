#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	uint size = memsize();
  	printf(1, "The process is using: %dB\n", size);

  	char * buffer = (char*)malloc(20 * KB);
	size = memsize();
	printf(1, "The process is using: %dB\n", size);

	free(buffer);
	size = memsize();
	printf(1, "The process is using: %dB\n", size);  	
  	exit();
}
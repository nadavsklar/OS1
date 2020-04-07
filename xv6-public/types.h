typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;
typedef long double ldouble;
typedef unsigned long long ullong;

struct perf
{
	int ps_priority;
	int stime;
	int retime;
	int rtime;
};

#define KB 			1024
#define INT_SIZE 	4
#define NULL		((void *)0)
#define STDOUT		1

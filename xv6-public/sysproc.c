#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int sys_proc_info(void)
{
  struct perf * performance;
  char * x;
  if (argptr(0, &x, sizeof(struct perf)) < 0)
    return -1;
  performance = (struct perf *) x;
  return proc_info(performance);
}

int sys_policy(void)
{
  int new_policy;
  if (argint(0, &new_policy) < 0)
    return -1;
  return policy(new_policy);
}

int sys_set_cfs_priority(void)
{
  int new_priority;
  if (argint(0, &new_priority) < 0)
    return -1;
  return set_cfs_priority(new_priority);
}

int sys_set_ps_priority(void)
{
  int new_priority;
  if (argint(0, &new_priority) < 0)
    return -1;
  return set_ps_priority(new_priority);
}

int
sys_exit(void)
{
  int exitcode;
  if (argint(0, &exitcode) < 0)
    return -1;
  exit(exitcode);
  return 0;  // not reached
}

int
sys_wait(void)
{
  int x;
  int* exitcode;
  if (argint(0, &x) < 0)
    return -1;
  exitcode = (int*) x;
  return wait(exitcode);
}

int 
sys_memsize(void)
{
  return myproc()->sz;
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

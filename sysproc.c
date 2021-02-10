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

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
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

int
sys_getParentID(void){
  struct proc*  my_procces=myproc();
  struct proc* my_parent_procces= my_procces->parent;
  return my_parent_procces->pid;

}

int
sys_getSyscallCounter(void)
{
  int input;
  if(argint(0, &input) < 0)
    return -1;
  int pid;
  pid = myproc()->pid;
  return syscallCounter(input, pid);
}


int
sys_getChildren(void)
{
  int curProcpid;
  curProcpid = myproc()->pid;
  return children(curProcpid);
}

int
sys_changePolicy(void){
  int n;

  if(argint(0, &n) < 0)
    return -1;
  if (n==ROUNDROBIN || n==ML_SCHED || n==P_SCHED ){
    MYPOLICY=n;
    return n;
  }
  else{
    return -1;
  }
}

int 
sys_changePriority(void){
  int n;
  if(argint(0, &n) < 0)
    return -1;
  if (n <1 || n>6)return -1;

  struct proc*  my_procces=myproc();
  my_procces->priority=n;
  return n;


}

int
sys_ps(void){
  struct proc*  my_procces=myproc();
  int n= my_procces->priority;
  return n;



}

int 
sys_wait_and_get_info(void){

  int *waiting_time;
  int* running_time;
  int * sleeping_time;
  int * termination_time;
  int * creation_time;
  if (argptr(0, (char **) &running_time, sizeof(int ))<0){
    return 12;
  }
  if (argptr(1, (char **) &waiting_time, sizeof(int ))<0){
    return 13;
  }
  if (argptr(2, (char **) &creation_time, sizeof(int ))<0){
    return 14;
  }
  if (argptr(3, (char **) &termination_time, sizeof(int ))<0){
    return 15;
  }
  if (argptr(4, (char **) &sleeping_time, sizeof(int ))<0){
    return 16;
  }

  int pid = wait_and_get_info(running_time,waiting_time,creation_time,termination_time,sleeping_time);
  return pid;
}



int
sys_changeQuantum(void){
  int newQuantum ;
  argint(0, &newQuantum);
  int result = changeQuantum(newQuantum);
  return result;
}


int
sys_get_priority(void){
  return myproc()->priority;
}
int
sys_test(void){
  return myproc()->counter;
}
int
sys_test2(void){
  return myproc()->sleeping_time;
}


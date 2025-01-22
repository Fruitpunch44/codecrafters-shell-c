#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#define   MAX_COUNT  2

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

int main()
{
     pid_t  pid;
     pid=fork();
     if (pid == 0) //child process id w
          ChildProcess();
     else 
          ParentProcess();
    return 0;
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d \n", i);
     printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     int   i;
    
     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d \n", i);
     printf("*** Parent is done ***\n");
}

/*it good to know that what fork does is create a copy of your main process 
simply put as it also copies the address space usally the return value for a
child process is 0  */
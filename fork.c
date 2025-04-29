#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main()
{
  pid_t pid ;
  pid = fork();
 
  if(pid == 0)  
  { 
    printf("child process running\n"); 
    printf("child PID : %d   parent PID : %d \n",getpid(),getppid());
    sleep(1);
    exit(0);
  }
  else if(pid > 0)
  { 
     printf("parent process running\n");
     printf("parent PID :%d   child PID  :%d \n",getpid(),getppid());
     wait(NULL);
  }
  else
  { 
    printf("fork fails");
    exit(1);
  }
}

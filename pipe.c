#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{
  int pipefd[2];
  char buffer[50];
  char msg[50];

  printf("Enter a data to be send :\n");
  scanf("%s",msg);

  //create pipe
  pipe(pipefd);

  //write data 
  write(pipefd[1],msg,strlen(msg));

  //read data
  read(pipefd[0],buffer,strlen(msg));

  printf("received buffer : %s\n",buffer);
  return 0;



}
	

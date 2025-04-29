#include <stdio.h>
#include <pthread.h>

void *print_even_thread(void *arg)
{
for(int i=0;i<=5;i++)
{
  if(i%2==0)
  printf("Even thread:%d\n",i);
  
}
return NULL;

}

void *print_odd_thread(void *arg)

{
for(int i=0;i<=5;i++)
{
if(i%2!=0)
printf("Odd thread:%d\n",i);

}
return NULL;

}

int main()
{

 pthread_t thread1;
 pthread_t thread2;
 
 pthread_create(&thread1,NULL,print_even_thread,NULL);
// pthread_join(thread1,NULL);

   
 pthread_create(&thread2,NULL,print_odd_thread,NULL);
 //pthread_join(thread2,NULL);
 
 pthread_exit(NULL);
 
 
   
 return 0;
 
}

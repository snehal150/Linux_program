#include <stdio.h>
#include <pthread.h>

void *print(void *arg)
{

char *msg =(char *)arg;
//int value= *(int *)arg;
 printf("%s\n",msg);
//printf("%d\n",value);
return NULL;

}

void *print_msg(void *arg)
{

char *msg =(char *)arg;
printf("%s\n",msg);
return NULL;

}

int main()
{

 pthread_t thread;
 pthread_t t;
 char *message = "hello from thread1";
 char *msg = "hello from thread2";
 //int val=42;
 pthread_create(&thread,NULL,print,(void*)message);
 pthread_create(&t,NULL,print_msg,(void*)msg);
 //pthread_create(&thread,NULL,print,(void*)&val);
 pthread_join(thread,NULL);
 pthread_join(t,NULL);
 return 0;
 
}

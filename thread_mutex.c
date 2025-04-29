#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock ;

void *thread_fun(void *arg)
{
  pthread_mutex_lock(&lock);
  printf("Thread %ld is inside critical section\n", (long)pthread_self());
  sleep(2); // simulate some long operation
  printf("Thread %ld is leaving critical section\n", (long)pthread_self());
  pthread_mutex_unlock(&lock);
  return NULL;
  
}

int main()
{
 pthread_t  t1,t2;
 
 pthread_mutex_init(&lock,NULL);

 pthread_create(&t1,NULL,thread_fun,NULL);
 pthread_create(&t2,NULL,thread_fun,NULL);
 
 pthread_join(t1,NULL);
 pthread_join(t2,NULL);
 
 pthread_mutex_destroy(&lock);
 return 0;
 
}


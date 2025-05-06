#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234

int main()
{
 int shmid;
 char *shm_ptr;
 
 //create shared memory
 shmid = shmget(SHM_KEY,1024 , 4567 | IPC_CREAT);
 shm_ptr = (char *)shmat(shmid, NULL, 0);

 // Step 2: Write to shared memory
 printf("Enter a message: ");
 fgets(shm_ptr, 1024, stdin);
 shm_ptr[strcspn(shm_ptr, "\n")] = 0;  // remove newline

 // Step 3: Read from shared memory
 printf("Reading from shared memory: %s\n", shm_ptr);

 // Step 4: Delete shared memory
 shmctl(shmid, IPC_RMID, NULL);

 // Step 5: Detach from shared memory
 shmdt(shm_ptr);

 return 0;
 	
}

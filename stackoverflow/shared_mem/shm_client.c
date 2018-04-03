/*
 *  * shm-client - client program to demonstrate shared memory.
 *   */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHMSZ     27
struct sh_mem_st {
	char semaphore;
	char command;
	char str[27];
};

int main()
{
	int shmid;
	key_t key;
	char *shm, *s;
	struct sh_mem_st *shared;

	/*
	 *      * We need to get the segment named
	 *           * "5678", created by the server.
	 *                */
	key = 5677;

	/*
	 *      * Locate the segment.
	 *           */
	if ((shmid = shmget(key, sizeof(struct sh_mem_st), 0666)) < 0) {
		perror("shmget");
		exit(1);
	}

	/*
	 *      * Now we attach the segment to our data space.
	 *           */
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		exit(1);
	}

	shared = (struct sh_mem_st *)shm;
	/*
	 *      * Now read what the server put in the memory.
	 *           */
	printf("struct after change:\n command: %d\n str: %s\n", shared->command, shared->str);
	while ( !shared->semaphore )
		sleep(1);
	shared->semaphore++;
	shared->command = 4;
	strcpy(shared->str, "client test");
	sleep (15);

	shmdt( shm );
	exit(0);
}

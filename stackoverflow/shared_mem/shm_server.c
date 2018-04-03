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
	char c;
	int shmid;
	key_t key;
	char *shm, *s;
	struct sh_mem_st *shared;
	/*
	 * We'll name our shared memory segment
	 * "5678".
	 */
	key = 5677;

	/*
	 * Create the segment.
	 */
	printf("sizeof(struct sh_mem_st) = %lu/n", sizeof(struct sh_mem_st) );
	if ((shmid = shmget(key, sizeof(struct sh_mem_st), IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(1);
	}

	/*
	 * Now we attach the segment to our data space.
	 */
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		exit(1);
	}

	/*
	 * Now put some things into the memory for the
	 * other process to read.
	 */
	shared = (struct sh_mem_st *)shm;
	shared->semaphore = 1;
	shared->command = 2;
	strcpy(shared->str,"test");
	printf("struct after change:\n command: %d\n str: %s\n", shared->command, shared->str);
	sleep(10);
	shared->semaphore--;
	sleep(10);

	while ( !shared->semaphore )
		sleep(1);

	printf("struct before exit:\n command: %d\n str: %s\n", shared->command, shared->str);
	shmdt( shm );
	exit(0);
}

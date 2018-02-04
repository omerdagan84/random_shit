#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>

bool runFlag = true;
int remote_pid = 0;

void signal_handler( int signal, siginfo_t *si, void *arg )
{
	int call_arg = si->si_value.sival_int;
	remote_pid = (int)si->si_pid;

	printf("recieved signal(%d) from pid(%d) with value(%d)\n",
			signal, remote_pid, call_arg);
	if ( call_arg == 255 ) {
		runFlag = false;
	}
}

void register_signal ( void ) 
{
	struct sigaction sa;
	printf("registering signal hook on USR2\n");

	memset( &sa, 0, sizeof( sigaction ) );
	sigemptyset( &sa.sa_mask );
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;

	sigaction( SIGUSR2, &sa, NULL );
}

int main(int argc, char *argv[])
{
	union sigval value;

	register_signal();

	printf("command will continue to recive command 16 until command 255 is recieved\n");
	while ( runFlag );

	/*announce end of run to -> readDB*/
	value.sival_int = 255;
	sigqueue(remote_pid, SIGUSR2, value); 
	return 0;
}

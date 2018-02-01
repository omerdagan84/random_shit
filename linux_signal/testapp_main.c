#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>

bool runFlag = true;
bool remoteFlag = true;

/* aux function to handle CTRL-C from the user */
void terminate_handler( int signal, siginfo_t *si, void *arg )
{
	runFlag = false;
}

/* aux function to handle signal from the main application */
void signal_handler( int signal, siginfo_t *si, void *arg )
{
	remoteFlag = false;
}

void register_signals()
{
	struct sigaction sa;
	struct sigaction sa_term;

	/* register SIGUSR2 to handle end of run*/
	memset( &sa, 0, sizeof( sigaction ) );
	sigemptyset( &sa.sa_mask );
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction( SIGUSR2, &sa, NULL );

	/* register SIGiTERM to handle CTRL_C from user*/
	memset( &sa_term, 0, sizeof( sigaction ) );
	sigemptyset( &sa_term.sa_mask );
	sa_term.sa_sigaction = terminate_handler;
	sa_term.sa_flags = SA_SIGINFO;
	sigaction( SIGINT, &sa_term, NULL );
}

int main(int argc, char *argv[])
{
	int remote_pid = atoi(argv[1]);
	union sigval value;

	register_signals();

	while ( runFlag )
	{
		/* send the command to the remote application */
		value.sival_int = 16;
		if(sigqueue(remote_pid, SIGUSR2, value) == 0) {
			printf("signal sent to pid: %d with command: %d\n", remote_pid, value.sival_int);
		} else {
			perror("SIGSENT-ERROR:");
		}
		sleep(1);
	}


	value.sival_int = 255;
	if(sigqueue(remote_pid, SIGUSR2, value) == 0) {
		printf("signal sent to pid: %d with command: %d\n", remote_pid, value.sival_int);
	} else {
		perror("SIGSENT-ERROR:");
	}

	printf("sent exit command to remote and exiting\n");
	return 0;
}

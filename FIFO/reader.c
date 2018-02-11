#define FIFO_PATH "/tmp/fifotest"
#define BUF_LEN 255

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

int createPipe( char *pipe )
{
	int ret;

	ret = mkfifo( pipe, 0666 );

	return ret;
}

int readPipe ( char *pipe, char *buf )
{
	int fd, readVal;

	fd = open( pipe, O_RDONLY );
	if ( fd < 0 )
		return -1;

	readVal = read( fd, buf, BUF_LEN );

	close( fd );

	return readVal;
}

int writePipe ( char *pipe, char *buf, int length)
{
	int fd;

	fd = open( pipe, O_WRONLY );
	if ( fd < 0 )
		return -1;

	write ( fd, buf, length );

	close( fd );

	return 0;
}

void *writer ()
{
	char buf[BUF_LEN] = {0};
	int myPid = getpid();

	sprintf( buf, "putting into fifo - mypid(%d)", myPid );
	while(1) {
		writePipe( FIFO_PATH, buf, strlen(buf) );
		sleep(1);
	}
}

void *reader () 
{
	char buf[BUF_LEN] = {0};
	int readBytes = 0;

	while(1) {
		readBytes = readPipe( FIFO_PATH, buf );
		if ( readBytes )
			printf(" read :'%s'\n", buf);
	}
}

int main (int argc, char *argv[])
{
	int retVal;
	int arg;
	pthread_t writerThread = 0;
	pthread_t readerThread = 0;

	createPipe( FIFO_PATH );
	arg = atoi( argv[1] );

	if (arg)
	{
		printf("configured as writer\n");
		retVal = pthread_create( &writerThread, NULL, writer, NULL );
		if ( retVal )
			return -1;
	} else {
		printf("configured as reader\n");
		retVal = pthread_create( &readerThread, NULL, reader, NULL );
		if ( retVal )
			return -1;
	}

	if (arg)
		pthread_join( writerThread, NULL);
	else
		pthread_join( readerThread, NULL);
}

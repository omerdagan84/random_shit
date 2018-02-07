#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

void _process( int sock )
{
	int n;
	int count = 20;
	char recvBuff[200];
	char sendBuff[200];
	memset(recvBuff, '0', sizeof(recvBuff));
	memset(sendBuff, '0', sizeof(sendBuff));


	while ( count-- ) {
		n = read(sock, recvBuff, sizeof(recvBuff)-1);
		if ( n > 0 )
		{
			recvBuff[n] = 0;
			printf("Recieved: %s\n", recvBuff);
		}
        snprintf(sendBuff, sizeof(sendBuff), "server sending...%d\r\n", count);
        write(sock, sendBuff, strlen(sendBuff));
		sleep (5);
	}
}

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 
	int pid = 0;

    char sendBuff[1025];
    char recvBuff[1025];
    time_t ticks; 

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 
    memset(recvBuff, '0', sizeof(recvBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10); 

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 

		pid = fork();

		if ( pid==0 ) {
			close(listenfd);
			_process(connfd);
			exit(0);
		} else {
			close(connfd);
		}
     }
}

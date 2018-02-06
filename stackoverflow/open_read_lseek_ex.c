#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

	int
main(void)
{
	int fd;
	char line[101] = {0};
	ssize_t readVal;
	int ret;

	fd = open("tmpp", O_RDONLY);
	if ( fd < 0 )
		exit(EXIT_FAILURE);

	readVal = read(fd, line, 100); 
	printf("Retrieved first %zu bytes:\n %s\n\n", readVal, line);

	readVal = read(fd, line, 100); 
	printf("Retrieved second %zu bytes:\n %s\n\n", readVal, line);
	
	ret = lseek(fd, 300, SEEK_SET);
	if ( ret < 0 ) {
		close( fd );
		return -1;
	}

	
	readVal = read(fd, line, 100); 
	printf("Retrieved third %zu bytes - at location 300:\n %s\n\n", readVal, line);
	close(fd);
	exit(EXIT_SUCCESS);
}

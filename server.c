#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main (void)
{
	pid_t	pid;

	printf("Server:\tI am %d\n",  getpid());
	pid = vfork();
	if (pid == 0)
	{
		/* this is child */
		printf("After vfork():\t created child %d of %d\n", getpid(), getppid());
		if (execl("/home/suser/test/network/client", "client", "p1", "p2", 0)<0)
		{
			printf("execl failed: %s\n", strerror(errno));
		}
		printf("After vfork():\tsuccessed");
		exit(0);
	}

	sleep(10);
	printf("Server:\tI am done %d\n", getpid());
}

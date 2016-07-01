#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netdb.h>

int main (void)
{
	pid_t	pid;
	short 	listenfd;
	struct sockaddr server_addr, client_addr;
	struct hostent *host;

	printf("Server:\tI am %d\n",  getpid());
	pid = vfork();

	/*** version new **/
	
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

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	printf ("%d\n", listenfd);

	host = gethostbyname("ol7bvm");
	if (host)
		printf("%s,%s\n", host->h_name, host->h_addr);

	bzero(&server_addr, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.s_addr = htol(q



	printf("Server:\tI am done %d\n", getpid());
}

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int i, count;

	printf("%s:\tI am %d\n",argv[0], getpid());

	printf("%s:\t", argv[0]);
	for (i=0; i<argc; i++)
	{
		printf("\t[%s]", argv[i]);
	}
	printf("\n");

	sleep(5);
	printf("%s:\tI am done%d\n",argv[0], getpid());
}	

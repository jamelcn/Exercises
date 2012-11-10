#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i;
	pid_t fpid;
	for (i = 0; i < 2; i++) {
		fpid = fork();
		if ( fpid == 0 ) {
			printf("\nchild process, process id : %d\t", getpid());
		} else {
			printf("\nparent process, process id : %d\t", getpid());
		}
		printf("-");
	}
	return 0;
}

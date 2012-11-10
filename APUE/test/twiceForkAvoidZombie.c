#include "apue.h"
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		perror("fork error");
	} else if (pid == 0) {                  /* first child */
		if ((pid = fork()) < 0) {
			perror("fock_error");
		} else if (pid > 0) {
			exit(0);                /* parent from second fork == first child */
		}

		sleep(2);
		printf("second child, parent pid = %d\n", getpid());
		exit(0);
	}

	if (waitpid(pid, NULL, 0) != pid) {
		perror("waitpid error");
	}
	return 0;
}

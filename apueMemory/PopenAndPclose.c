#include "apue.h"
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

static pid_t *childpid = NULL;

static int maxfd;

FILE* popen(const char *cmdstring, const char *type)
{
	int i;
	int pfd[2];
	pid_t pid;
}

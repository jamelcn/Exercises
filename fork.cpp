#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
    fork();
    fork() && fork() || fork();
    fork();
    printf("+\n");
	return 0;
}

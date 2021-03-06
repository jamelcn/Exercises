#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int rand7()
{
	return rand() % 7 + 1;
}

int rand10()
{
	int a71, a72, a10;
	int count = 0;
	do {
		a71 = rand7() - 1;
		a72 = rand7() - 1;
		a10 = a71 * 7 + a72;
		printf("%d : a71=%d, a72=%d, a10=%d\n", ++count, a71, a72, a10);
		sleep(1);
	} while (a10 >= 40);
	return (a71*7+a72)/4 + 1;
}

int main(int argc, const char *argv[])
{
    while (1) {
	int a10 = rand10();
	printf("a10 = %d\n", a10);
	printf("rand() = %d\n", rand());
	getchar();
    }
	return 0;
}

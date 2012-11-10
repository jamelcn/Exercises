#include <stdio.h>
void swap(int a, int b)
{
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}

int main(int argc, const char *argv[])
{
	int a = 3, b = 4;
	swap(a, b);
	printf("%d %d\n", a, b);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

int main(int argc, const char *argv[])
{
	int i,j;
	int b[11] = { -1, 5, 4, 1, 7, 9, 3, 8, 2, 6, 0 };
	int lenOfB = sizeof(b)/sizeof(b[0]);
	for (i = 2; i < lenOfB; i++) {
		b[0] = b[i];
		for (j = i-1; b[j] > b[0]; j--) {
			b[j+1] = b[j];
		}
		b[j+1] = b[0];
	}

	print(b, lenOfB);
	return 0;
}





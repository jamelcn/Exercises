#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"


/*-----------------------------------------------------------------------------
 *  待改进
 *-----------------------------------------------------------------------------*/

int main(int argc, const char *argv[])
{
    int i, j, lastExIndex = 0;
    int len = sizeof(a)/sizeof(a[0]);
    i = 0;
    while (i < len-1) {
	lastExIndex = -1;
	for (j = i+1; j < len-i; j++) {
		if (a[j-1] > a[j]) {
		    print(a, len);
		    printf("Swapping a[%d]:%d and a[%d]:%d\n",j-1,a[j-1],j,a[j]);
		    swap(&a[j-1], &a[j]);
			lastExIndex = j;
		}
	}
	printf("\nlastExIndex:%d\n", lastExIndex);
	if (lastExIndex == -1) break;
    }

    print(a, len);
	return 0;
}

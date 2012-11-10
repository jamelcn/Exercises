#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

int main(int argc, const char *argv[])
{
	int i, j;

	for( i = 0; i < 10-1; ++i ) {
	    for ( j = i+1; j < 10; ++j ) {
		if ( a[i] > a[j] ) {
		    swap(&a[i], &a[j]);
		}
	    }
	}
	
	print(a, 10);
	return 0;
}

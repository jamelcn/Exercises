#include <stdio.h>

int strcmp(const char* s, const char *t)
{
	assert(s != NULL && t != NULL);
	while ( *s && *t && *s == *t ) {
		++s;
		++t;
	}
	return (*s - *t);
}

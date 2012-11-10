#include <stdio.h>

char * strchr(const char *str, int c)
{
	assert(str != NULL);
	for (; *str != (char)c; +str)
		if (*str == '\0') {
			return NULL;
		}
	return str;
}

#include <stdio.h>

char * strcat(char* strDst, const char* strSrc)
{
	assert((strDst != NULL) && (strSrc != NULL));
	char *address = strDst;
	while (*strDst != '\0') 
		++strDst;
	while ( (*strDst++ = *strSrc++) != '\0') 
		;
	return address;
}

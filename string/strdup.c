#include <stdio.h>

char * strdup(char *strSrc)
{
	if (strSrc != NULL) {
		char *start = strSrc;
		int len = 0;
		while ( *strSrc++ != '\0' )
			len++;
		
		char *address=(char *)malloc(len+1);
		assert(address != NULL);

		while ((*address++ = *start++) != '\0') 
			;
		return address-(len+1);
	}
	return NULL;
}

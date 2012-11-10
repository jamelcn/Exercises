#include <stdio.h>

char * strcpy(char *dst,const char *src)
{
	if (dst == src) 
		return dst;
	assert( (dst != NULL) && (src != NULL) );
	char *address = dst;
	while ( (*dst++ = *src++) ) 
		;
	return address;

}

char * strncpy(char *strDst, const char *strSrc, unsigned int count)
{
	assert(strDst != NULL && strSrc != NULL);
	char *address = strDst;
	while (count-- && *strSrc != '\0') 
		*strDst++ = *strSrc++;
	*strDst = '\0';
	return address;
}

#include <stdio.h>

int strstr(const char *string, const char *substring)
{
	if (string == NULL || substring == NULL) {
		return -1;
	}

	int lenstr = strlen(string);
	int lensub = strlen(substring);

	int len = lenstr - lensub;
	int i,j;
	for (i = 0; i <= len; i++) {
		for (j = 0; j <= lensub; j++) {
			if (string[i+j] != substring[j]) 
				break;
		}
		if (j == lensub) 
			return i + 1;
	}
	return -1;
}

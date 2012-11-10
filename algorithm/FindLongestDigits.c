#include <stdio.h>
#include <string.h>
#include <ctype.h>

void FindLongestDigits(char str[], int len)
{
	int maxcount = 0, count = 0, i = 0, left = 0, maxLeft = -1;
	if (len < 0 || str == NULL) {
		return;
	}
	while (left < len) {
		count = 0;
		while (!isdigit(str[left]) && (left < len)) 
			left++;
		while (isdigit(str[left]) && (left < len)) {
			left++;
			count++;
		}
		if (count > maxcount) {
			maxcount = count;
			maxLeft = left-count;
		}
	}
	for (i = maxLeft; i < maxLeft+maxcount; i++) 
		putchar(str[i]);
}

int main(int argc, const char *argv[])
{
	char str[100] = "fafdahruqa12343fa43faf56454354fas";
	FindLongestDigits(str, strlen(str));
	return 0;
}

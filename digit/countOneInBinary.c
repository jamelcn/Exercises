#include <stdio.h>
#include <stdlib.h>

int v1(unsigned char ch, int count)
{
    while ( ch != 0 ) {
	count += ch & 0x01;
	ch >>= 1;
	printf("%x\n", ch);
    }
    return count;
}

int v2(unsigned char ch, int count)
{
    while (ch) {
    	ch &= (ch-1);
	count++;
    }
    return count;
}

int main(int argc, const char *argv[])
{
	unsigned char ch=0xef;
	int count = 0;

	//count = v1(ch, count);
	count = v2(ch, count);

	printf("%x has %d \"1\" in binary \n", ch, count);
	ch=0;
	return 0;
}

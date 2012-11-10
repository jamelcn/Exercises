#include <iostream>
#define STRLEN 101

using namespace std;

char str[STRLEN];

int countLongest(char *pBuf)
{
	int result = 0, result2 = 0;
	char *p = pBuf;

	if ( *p == 0 ) {
		return result;
	}

	while ( (*p != 0 ) && (*p == *pBuf)) {
	    ++result;
	    ++p;
	}
	result2 = countLongest(++pBuf);
	return result > result2 ? result : result2;
}

int main(int argc, const char *argv[])
{
    printf("Enter a string:\n");
    fgets(str,sizeof(str), stdin);
    cout<<countLongest(str)<<endl;
    return 0;
}

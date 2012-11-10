#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <numeric>
using namespace std;

int main(int argc, const char *argv[])
{
	char s[] = "C++ is a better C";
	int len = strlen(s);
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout<<"Accumulate a:"<<accumulate(a, a+9, 0)<<endl;
	cout<<s<<endl;
	const char* where = find(&s[0], &s[len], 'e');
	cout<<where<<endl;
	return 0;
}

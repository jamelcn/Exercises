#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, const char *argv[])
{
	string str("abc");
	string::size_type ix;
	for (ix = 0; ix != str.size(); ix++) {
		str[ix] = toupper(str[ix]);
	}
	cout<<str<<endl;
	for (ix = 0; ix != str.size(); ix++) {
		str[ix] = '*';
	}
	cout<<str<<endl;
	return 0;
}

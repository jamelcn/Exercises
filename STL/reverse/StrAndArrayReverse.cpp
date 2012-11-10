#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;


int main(int argc, const char *argv[])
{
	cout<<"Using reverse algorithm with a string"<<endl;
	string string1 = "mark twain";
	reverse(string1.begin(), string1.end());
	assert(string1 == "niawt kram");
	cout<<" --- ok."<<endl;

	cout<<"Using reverse algorithm with a array"<<endl;
	char array1[] = "mark twain";
	int N1 = strlen(array1);
	reverse(&array1[0], &array1[N1]);
	assert(string(array1) == "niawt kram");
	cout<<" --- ok."<<endl;
	return 0;
}

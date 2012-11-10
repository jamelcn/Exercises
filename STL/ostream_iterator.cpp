#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main(int argc, const char *argv[])
{
	list<int> list1;

	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(1);
	list1.push_back(11);
	list1.push_back(9);
	list1.push_back(-1);
	ostream_iterator<int> out (cout, "\n");
	copy(list1.begin(), list1.end(), out);
	return 0;
}

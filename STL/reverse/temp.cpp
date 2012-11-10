#include <iostream>
#include <map>
#include <string>
using  namespace std;

int main(int argc, const char *argv[])
{
	map<string, long> directory;
	directory["Bogart"] = 1234567;
	directory["Bacall"] = 9876543;
	directory["Cagney"] = 3459876;

	string name;
	while (cin >> name) 
	    if (directory.find(name) != directory.end()) 
		cout<<"The phone number for "<<name
		    <<" is "<<directory[name]<<endl;
	    else
		cout<<"Sorry, no listing for "<<name<<endl;
	return 0;
}

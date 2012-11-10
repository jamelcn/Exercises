#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>);

void deleteElem1()
{
    vector<int> array;
    array.push_back(1);
    array.push_back(7);
    array.push_back(6);
    array.push_back(3);

    vector<int>::iterator itor;
    vector<int>::iterator itor2;
    itor = array.begin();

    for (itor = array.begin(); itor != array.end(); itor++) 
    {
	if ( *itor == 6 ) {
		itor2 = itor;
		array.erase(itor2);
	}
    }
    print(array);
}

void deleteElem2()
{
    vector<int> array;
    array.push_back(1);
    array.push_back(7);
    array.push_back(6);
    array.push_back(3);

    vector<int>::iterator itor;
    vector<int>::iterator itor2;
    itor = array.begin();
    array.erase( remove( array.begin(), array.end(), 6 ), array.end() );
    print(array);
}

int main(int argc, const char *argv[])
{
    //deleteElem1();
    deleteElem2();
    return 0;
}

void print(vector<int> v)
{
	cout<<"vector size is:"<<v.size()<<endl;
	vector<int>::iterator p = v.begin();
	for( ; p != v.end(); ++p )
	{
	    cout<<*p<<" ";
	}
	cout<<endl;
}

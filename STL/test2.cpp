#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
#include <cassert>

//using namespace std;
using std::cout;
using std::endl;
using std::vector;
using std::list;

template<typename T1, typename T2>
class pair
{
    public:
	T1 first;
	T2 second;
	pair() : first(T1()), second(T2()) {  }
	pair(const T1& x, const T2& y) : first(x), second(y) {  }
};

template<typename T>
T max(T x, T y)
{
    if (x < y)
	return y;
    else
	return x;
}

vector<char> vec(const char s[])
{
    return vector<char>(&s[0], &s[strlen(s)]);
}

bool operator <(const pair<double, long>& x, const pair<double, long>& y)
{
	return (x.first < y.first) || ((x.first == y.first) && (x.second < y.second));
}

template<typename Container>
Container make_container(const char s[])
{
    return Container(&s[0], &s[strlen(s)]);
}

int main(int argc, const char *argv[])
{
    int u = 3;
    int v = 4;
    pair<double, long> pair5(3.1415, 999);
    pair<double, long> m = max(pair5, pair5);
    char s[] = "Hello world!";
    cout<<max(u, v)<<endl;
    list<char> L = make_container< list<char> >(s);
    vector<char> V = make_container< vector<char> >(s);
    vector<char>::iterator vit;
    for (vit = V.begin(); vit != V.end(); vit++) 
	cout<<*vit;
    cout<<endl;
    reverse(V.begin(), V.end());
    for (vit = V.begin(); vit != V.end(); vit++) 
	cout<<*vit;
    assert(V == make_container< vector<char> >("!dlrow olleH"));
    cout << endl << " --- ok." << endl;
    return 0;
}

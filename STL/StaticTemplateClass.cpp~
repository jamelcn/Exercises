#include <iostream>
using namespace std;

template<class T>
class Operate {
public:
	Operate (){};
	virtual ~Operate (){};
	static T Add(T a, T b)
	{
		return a+b;
	}
	static T Mul(T a, T b)
	{
		return a*b;
	}
	static T Judge(T a, T b=1)
	{
		if ( a >= 0 ) {
			return a;
		} else {
			return a/b;
		}
	}

private:
	/* data */
};

int main(int argc, const char *argv[])
{
	int A, B, C, D, E, x, y, z;
	A = 1, B = 2, C = 3, D = 4, E = 5;
	x = Operate<int>::Add(A, B);
	y = Operate<int>::Mul(C,D);
	z = Operate<int>::Judge(E,B);
	cout<<x<<endl<<y<<endl<<z<<endl;
	return 0;
}

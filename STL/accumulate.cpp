#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>                              /* for accumulate */
#include <functional>                           /* for multiplies */
using namespace std;

// Version 1 ------------------------------
int mult(int x, int y)
{
	return x * y;
}

void ac1()
{
    int x[5] = {2, 3, 5, 7, 11};
    vector<int> vector1(&x[0], &x[5]);

    int product = accumulate(vector1.begin(), vector1.end(), 1, mult);
    cout << "product:" << product<<endl;
}

// Version 2 ------------------------------
class multiply
{
    public:
	int operator()(int x, int y) const { return x * y; }
};

void ac2()
{

    int x[5] = {2, 3, 5, 7, 11};
    vector<int> vector1(&x[0], &x[5]);

    int product = accumulate(vector1.begin(), vector1.end(), 1, multiply());
    cout << "product:" << product<<endl;
}

// Version 3 ------------------------------
// The Following Code is Defined In Stl
//template<typename T>
//class multiplies : public binary_function<T, T, T> {
//    public:
//        T operator() (const T& x, const T& y) const {
//            return x * y;
//        }
//};

void ac3()
{

    int x[5] = {2, 3, 5, 7, 11};
    vector<int> vector1(&x[0], &x[5]);

    int product = accumulate(vector1.begin(), vector1.end(), 1, multiplies<int>());
    cout << "product:" << product<<endl;
}

int main(int argc, const char *argv[])
{
    ac2();
    return 0;
}

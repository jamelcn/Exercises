#include <iostream>
using namespace std;

class Base { virtual void f() {  } };
class Derived : public Base {  };

int main(int argc, const char *argv[])
{
	Base b, *pb;
	pb = NULL;
	Derived d;

	cout << typeid(int).name() << endl
		<< typeid(unsigned).name() << endl
		<< typeid(long).name() << endl
		<< typeid(unsigned long).name() <<endl
		<< typeid(char).name() << endl
		<< typeid(unsigned char).name() << endl
		<< typeid(float).name() << endl
		<< typeid(double).name() << endl
		<< typeid(string).name() << endl
		<< typeid(Base).name() << endl
		<< typeid(b).name()<<endl
		<< typeid(pb).name()<<endl
		<< typeid(Derived).name() << endl
		<< typeid(d).name()<<endl
		<< typeid(type_info).name() << endl;

	Base *pb2 = dynamic_cast<Base *>(new Derived);
	Base &b2 = d;
	Base *pb3 = &d;
	cout << typeid(pb2).name() << endl
		<< typeid(b2).name() <<endl
		<< typeid(pb3).name() << endl
		<< typeid(*pb3).name() << endl;

	cout << typeid(7.84).name() << endl
		<< typeid(Base*).name() << endl
		<< typeid(&pb3).name() << endl;

	return 0;
}

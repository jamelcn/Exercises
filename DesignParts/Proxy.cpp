#include <iostream>
#include <string>
using namespace std;

// define interface
class Interface
{
    public:
	virtual void Request() = 0;
};

// define real class
class RealClass : public Interface
{
    public:
	virtual void Request()
	{
	    cout<<"真实的请求"<<endl;
	}
	virtual ~RealClass() {  }
};

// Proxy Class
class ProxyClass : public Interface
{
    private:
	RealClass* m_realClass;
    public:
	virtual void Request()
	{
	    // Process something ...
	    m_realClass = new RealClass();
	    m_realClass->Request();
	    delete m_realClass;
	}
};

int main(int argc, const char *argv[])
{
	ProxyClass* pc = new ProxyClass();
	pc->Request();
	return 0;
}

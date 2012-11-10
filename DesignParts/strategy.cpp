#include <iostream>
using std::cin;
using std::cout;
using std::endl;


class COperation
{
    public:
	double m_nFirst;
	double m_nSecond;
	COperation(double a, double b)
	    : m_nFirst(a), m_nSecond(b)
	{

	}
	virtual double GetResult()
	{
	    return 0;
	}
};

class AddOperation: public COperation
{
    public:
	AddOperation(double a, double b)
	    : COperation(a, b)
	{

	}
	virtual double GetResult()
	{
	    return m_nFirst + m_nSecond;
	}
};

class SubOperation: public COperation
{
    public:
	SubOperation(double a, double b)
	    : COperation(a, b)
	{

	}
	virtual double GetResult()
	{
	    return m_nFirst - m_nSecond;
	}
};

class Context
{
    public:
	Context(COperation *temp)
	{
	    op = temp;
	}
	double GetResult()
	{
	    return op->GetResult();
	}

    private:
	COperation* op;
};

int main(int argc, const char *argv[])
{
    double a, b;
    char c;
    Context *pct;
    cout<<"Please enter two integer:";
    cin>>a>>b;
    cout<<"Please enter an operator:";
    cin>>c;
    switch(c)
    {
	case '+':
	    pct = new Context(new AddOperation(a, b));
	    break;
	case '-':
	    pct = new Context(new SubOperation(a, b));
	    break;
	default:
	    pct = new Context(new COperation(a, b));
	    break;
    }
    cout<<pct->GetResult()<<endl;
    return 0;
}

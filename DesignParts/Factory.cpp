#include <iostream>
using namespace std;

// Server:
class COperation
{
    public:
	int m_nFirst;
	int m_nSecond;

	virtual double GetResult()
	{
	    return 0;
	}
};

class AddOperation: public COperation
{
    public:
	virtual double GetResult()
	{
	    return m_nFirst + m_nSecond;
	}
};

class SubOperation: public COperation
{
    public:
	virtual double GetResult()
	{
	    return m_nFirst - m_nSecond;
	}
};

class CCalculatorFactory
{
    public:
	static COperation* Create(char COperation);
};

COperation* CCalculatorFactory::Create(char op)
{
    COperation* oper = NULL;
    switch(op)
    {
	case '+':
	    oper = new AddOperation();
	    break;
	case '-':
	    oper = new SubOperation();
	    break;
	default:
	    oper =  new AddOperation();
	    break;
    }
    return oper;
}


// Client:
int main(int argc, const char *argv[])
{
    int a, b;
    char cop;
    cout<<"Enter two interger:";
    cin>>a>>b;
    cout<<"Enter a operator:";
    cin>>cop;
    COperation* oper = CCalculatorFactory::Create(cop);
    oper->m_nFirst = a;
    oper->m_nSecond = b;
    cout<<oper->GetResult()<<endl;
    return 0;
}

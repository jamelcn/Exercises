// observer Design Patterns

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SecretaryBase;

class CObserverBase
{
    protected:
	string name;
	SecretaryBase* sub;

    public:
	CObserverBase(string strname, SecretaryBase* strsub)
	    : name(strname), sub(strsub)
	{  }
	virtual void Update() = 0;
};

class StockObserver : public CObserverBase
{
    public:
	StockObserver(string strname, SecretaryBase* strsub)
	    : CObserverBase(strname, strsub)
	{  }
	virtual void Update();
};

class NBAObserver : public CObserverBase
{
    public:
	NBAObserver(string strname, SecretaryBase* strsub)
	    : CObserverBase(strname, strsub)
	{  }
	virtual void Update();
};

class SecretaryBase
{
    public:
	virtual void Attach(CObserverBase* observer) = 0;
	virtual void Notify() = 0;
	string action;
    protected:
	vector<CObserverBase*> observers;
};

class Secretary : public SecretaryBase
{
    public:
	void Attach(CObserverBase* ob)
	{
	    observers.push_back(ob);
	}

	void Notify()
	{
	    vector<CObserverBase*>::iterator it = observers.begin();
	    while (it != observers.end()) {
		(*it)->Update();
		it++;
	    }
	}
};

void StockObserver::Update()
{
    cout<<name<<":"<<sub->action<<",不要玩股票了，要开始工作了"<<endl;
}

void NBAObserver::Update()
{
    cout<<name<<":"<<sub->action<<",不要看NBA了，老板来了"<<endl;
}

int main(int argc, const char *argv[])
{
	SecretaryBase* secrty = new Secretary();
	CObserverBase* s1 = new NBAObserver("小李", secrty);
	CObserverBase* s2 = new StockObserver("小赵", secrty);
	secrty->Attach(s1);
	secrty->Attach(s2);
	secrty->action = "老板来了";
	secrty->Notify();
	return 0;
}

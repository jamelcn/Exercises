#include <string>
#include <iostream>
#include <vector>

using namespace std;

class SecretaryBase;

// abstract observer
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

// Specific Stock Observer
class StockObserver : public CObserverBase
{
    public:
	StockObserver(string strname, SecretaryBase* strsub)
	    : CObserverBase(strname, strsub)
	{  }
	virtual void Update();
}; 

// Specific NBA Observer
class NBAObserver : public CObserverBase
{
    public:
	NBAObserver(string strname, SecretaryBase* strsub)
	    : CObserverBase(strname, strsub)
	{ }
	virtual void Update();
};

// Abstract Notifier
class SecretaryBase
{
    public:
	string action;
	vector<CObserverBase*> observers;

    public:
	virtual void Attach(CObserverBase* observer) = 0;
	virtual void Notify() = 0;
};

// Specific Notifier
class Secretary : public SecretaryBase
{
    public:
	void Attach(CObserverBase* ob)
	{
	    observers.push_back(ob);
	}
	
	void Notify()
	{
	    vector<CObserverBase*>::iterator iter = observers.begin();
	    while(iter != observers.end())
	    {
		(*iter)->Update();
		iter++;
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
	SecretaryBase* secrty = new Secretary(); /* 创建观察者 */

	// 被观察的对象
	CObserverBase* s1 = new NBAObserver("小李", secrty);
	CObserverBase* s2 = new StockObserver("小赵", secrty);
	
	// 加入观察队列
	secrty->Attach(s1);
	secrty->Attach(s2);

	// Event
	secrty->action = "老板来了";
	// 通知 
	secrty->Notify();
	
	return 0;
}

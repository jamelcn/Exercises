#include <iostream>
#include <string>
using namespace std;

class LeiFeng
{
    public:
	virtual void who()
	{
	    cout<<"LeiFeng"<<endl;
	}
	virtual ~LeiFeng() {  }
};

class Student : public LeiFeng
{
    public:
	virtual void who()
	{
	    cout<<"Student"<<endl;
	}
};

class Volunteer : public LeiFeng
{
    public:
	virtual void who()
	{
	   cout<<"Volunteer"<<endl;  
	}
};

class LeiFengFactory
{
    public:
	virtual LeiFeng* createLeiFeng()
	{
	    return new LeiFeng();
	}
	virtual ~LeiFengFactory() {  }
};

class StudentFactory : public LeiFengFactory
{
    public:
	virtual Student* createLeiFeng()
	{
	    return new Student();
	}

};

class VolunteerFactory : public LeiFengFactory
{
    public:
	virtual Volunteer* createLeiFeng()
	{
	    return new Volunteer();
	}
};

int main(int argc, const char *argv[])
{
    LeiFengFactory *lff = new StudentFactory();
    LeiFeng* lf = lff->createLeiFeng();
    lf->who();
    delete lff;
    delete lf;
    return 0;
}


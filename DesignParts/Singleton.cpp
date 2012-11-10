#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CSingleton
{
    public:
	static CSingleton* GetInstance()
	{
	    if ( NULL == single ) {
	    	single = new CSingleton();
	    }
	    return single;
	}

    private:
	CSingleton() {}
	static CSingleton* single;
};

CSingleton* CSingleton::single = NULL;          /* 注意静态变量类外初始化 */

int main(int argc, const char *argv[])
{
	CSingleton* s1 = CSingleton::GetInstance();
	CSingleton* s2 = CSingleton::GetInstance();
	if (s1 == s2) cout<<"s1 = s2"<<endl;
	else cout<<"s1 != s2"<<endl;
	return 0;
}

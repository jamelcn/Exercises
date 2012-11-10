#include <iostream>
using namespace std;

class CSingleton
{
    public:
	static CSingleton* GetInstance()
	{
	    if (m_pInstance == NULL) 
		m_pInstance = new CSingleton();
	    return m_pInstance;
	}

    private:
	CSingleton() {};
	static CSingleton* m_pInstance;

	class CGarbo
	{
	    public:
		~CGarbo() 
		{
		    if (CSingleton::m_pInstance) 
			delete CSingleton::m_pInstance;
		}
	};
	static CGarbo Garbo;
};

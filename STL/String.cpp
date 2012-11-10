#include <iostream>
#include <cstdlib>

using namespace std;

class string
{
    public:
	String(const char* str = NULL);
	string(const String &other);
	~String(void);
	String & operator=(const String &other);
	
    private:
	char *m_data;
};

String::~String(void)
{
    delete [] m_data;
}

String::String(const char*str)
{
    if (str == NULL) {
    	m_data = new char[1];
	*m_data = '\0';
    } else {
    	int length = strlen(str);
	m_data = new char[length+1];
	strcpy(m_data, str);
    }
}

String::String(const String &other)
{
    if(other.m_data == NULL)
    {
	delete m_data;
	m_data = NULL;
	return;
    }

    int length = strlen(other.m_data);
    m_data = new char[length+1];
    strcpy
}

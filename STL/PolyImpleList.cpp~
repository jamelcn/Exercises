#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>
struct tcontainer {
	virtual void push(const T&) = 0;
	virtual void pop() = 0;
	virtual const T& begin() = 0;
	virtual const T& end() = 0;
	virtual size_t size() = 0;
};

template<typename T>
struct tvector : public tcontainer<T> {
    static const size_t step = 100;
    tvector() : itssize(0), cap(step), buf(0)
    {
	re_capacity(cap);
    }
    ~tvector() { free(buf); }

    void re_capacity(size_t s)
    {
    	if (!buf) 
	    buf = (T*)malloc(sizeof(T)*s);
	else
	    buf = (T*)realloc(buf, sizeof(T)*s);
    }

    virtual void push(const T& v)
    {
	if ( itssize >= cap ) 
	    re_capacity( cap += step );
	buf[itssize++] = v;
    }

    virtual void pop()
    {
    	if (itssize) 
	    itssize--;
    }

    virtual const T& begin()
    {
	return buf[0];
    }

    virtual const T& end()
    {
    	if (itssize) 
	    return buf[itssize-1];
	return 0;
    }

    virtual size_t size()
    {
    	return itssize;
    }

    const T& operator[] (size_t i)
    {
    	if (i >= 0 && i < itssize)	   
	    return buf[i];
    }

    private:
    size_t itssize;
    size_t cap;
    T* buf;

};

int main(int argc, const char *argv[])
{
	tvector<int> v;
	for (int i = 0; i < 10; ++i) 
	    v.push(i);
	for (int i = 0; i < 10; ++i)
	    cout<<v[i]<<endl;
	return 0;
}

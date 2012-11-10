const int * find1(const int *array, int n, int x)
{
	const int *p = array;
	for ( int i = 0; i < n; ++i )
	{
	    if ( *p == x ) {
	    	return p;
	    }
	    ++p;
	}   
	return 0;
}

template<typename T>
const int* My_Find(T *array, T n, T x)
{
    const T* p = array;
    int i = 0;
    for (i = 0; i < n; i++) 
    {
	if ( *p == x ) {
		return p;
	}
	++p;
    }
    return 0;
}

template<typename T>
const T* My_Find2(const T* s, const T* e, T x)
{
    const T* p = s;
    while ( p != e ) {
	if ( *p == x ) {
	    return p;
	}		
	++p;
    }
    return e;
}

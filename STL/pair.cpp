
namespace mystd {
    template<class T1, class T2>
	struct pair {
	    typedef T1 first_type;
	    typedef T2 second_type;

	    // default constructor
	    pair() : first(T1()), second(T2())
	    {}

	    // constructor
	    pair(const T1& t1, const T2& t2)
		: first(t1), second(t2)
	    {}

	    // copy constructor
	    template<class U, class V>
		pair(const pair<U,V>& rhs)
		: first(rhs.first), second(rhs.second)
		{}

	    // data member
	    T1 first;
	    T2 second;
	};


    template<class T1, class T2>
	bool operator== (const pair<T1,T2>&, const pair<T1,T2>&);

    template<class T1, class T2>
	bool operator< (const pair<T1,T2>&, const pair<T1,T2>&);

    template<class U, class V>
	pair<U,V>& make_pair(U u, V v)
	{
	    return pair(u, v);
	}
}

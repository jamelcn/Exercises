//----------tmutex.h开始----------
//实现linux的互斥信号量c++封装
//
#ifndef TMUTEX_H
#define TMUTEX_H

#include <pthread.h>

//线程互斥量
struct ThreadMutex {
	ThreadMutex()
	{
	    pthread_mutex_init(&mtx, NULL);
	}

	~ThreadMutex()
	{
	    pthread_mutex_destroy(&mtx);
	}

	inline void lock()
	{
	    pthread_mutex_lock( &mtx );
	}

	inline void unlock()
	{
	    pthread_mutex_unlock( &mtx );
	}

	pthread_mutex_t mtx;

};

//空互斥量，即调用lock时什么事都不做。
struct NullMutex {
	inline void lock()
	{
	    
	}

	inline void unlock()
	{
		
	}
};

template<class T>
class CAutoGuard
{
    public:
	CAutoGuard(T &mtx): m_mtx(mtx) {
	    m_mtx.lock();
	}

	~CAutoGuard()
	{
	    m_mtx.unlock();
	}

    protected:
	T &m_mtx;
};

#define AUTO_GUARD( guard_tmp_var, MUTEX_TYPE, mtx ) CAutoGuard<MUTEX_TYPE> guard_tmp_var(mtx)
#endif
//----------tmutex.h结束----------


//----------主程序文件test.cpp开始----------


#include <pthread.h>
//#include "tmutex.h"
#include <iostream>
using namespace std;

//typedef ThreadMutex MUTEX_TYPE;                 [> 使用线程互斥量的互斥量类型 <]
typedef NullMutex MUTEX_TYPE;                 /* 不使用线程互斥量的互斥量类型 */

MUTEX_TYPE g_mtx;                               /* 互斥量变量定义 */

void *print_msg_thread(void *parg);

void * print_msg_thread(void *parg)
{
	// 工作线程，用循环模拟一个工作
	char *msg = (char *)parg;

	AUTO_GUARD(gd, MUTEX_TYPE, g_mtx);
	for (int i = 0; i < 10; i++) {
		cout << msg << endl;
		sleep(1);
	}
	return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t t1, t2;

	// 创建两个工作线程，第一个打印10个1，第二个打印10个2.
	pthread_create( &t1, NULL, &print_msg_thread, (void *)"1" );
	pthread_create( &t2, NULL, &print_msg_thread, (void *)"2" );

	// 等待线程结束
	pthread_join( t1, NULL );
	pthread_join( t2, NULL );
	return 0;
}
//----------主程序文件test.cpp结束----------

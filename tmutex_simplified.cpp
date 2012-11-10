#include <pthread.h>
#include <iostream>
using namespace std;

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
} ;

ThreadMutex g_mtx;

void *print_msg_thread(void *parg)
{
    char *msg = (char *)parg;

    g_mtx.lock();
    for (i = 0; i < 10; i++) {
    	cout << msg <<end;
	sleep(1);
    }
    g_mtx.unlock();
    return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t t1, t2;

	pthread_create( &t1, NULL, &print_msg_thread, (void *)"1" );
	pthread_create( &t2, NULL, &print_msg_thread, (void *)"2" );

	pthread_join( t1, NULL );
	pthread_join( t2, NULL );
	return 0;
}

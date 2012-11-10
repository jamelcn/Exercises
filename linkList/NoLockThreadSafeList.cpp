#include <iostream>

//bool compare_and_swap(int *accum, int *oldval, int *newval)
bool CAS(int *accum, int *oldval, int *newval)
{
    if ( *accum == *oldval ) {
	*accum = *newval;
	return true;
    }
    return false;
}

void EnQueue(x)	// 进队列改良版
{
    q = new record();
    q->value = x;
    q->next = NULL;

    p = tail;
    oldp = p;
    do {
	while ( p->next != NULL ) 
	    p = p->next;
    } while ( CAS(p->next, NULL, q) != true ); /* 如果没有把结点连上，再试 */
    CAS(tail, oldp, q); /* 置尾结点 */
}

void DeQueue()
{
    do {
	p = head;
	if ( p->next == NULL ) {
	    return ERR_EMPTY_QUEUE;
	}
    } while ( CAS(head, p, p->next) != true );
    return p->next->value;
}

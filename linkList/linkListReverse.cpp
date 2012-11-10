#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char name[3];
    Node *next;
    Node(const char *p)
    {
	strcpy(name, p);
	next = NULL;
    }
};

Node * ReverseList(Node *& pHead) 
{
    Node *p1 = pHead;
    if (pHead == NULL || pHead->next == NULL) {
    	return pHead;
    }
    Node *p2, *p3;
    p3 = NULL;
    while (p1 != NULL) {
    	p2 = p1->next;
	p1->next = p3;
	p3 = p1;
	p1 = p2;
    }
    pHead = p3;
    return pHead;
}

Node * MakeList(Node *& pHead, const char *s) 
{
    char const *p = s;
    char name[3];
    Node * pNode, *pTail;
    while (*p != '\0') {
	name[0] = *p;
	name[1] = '\0';
	pNode = new Node(name);
	if (pHead == NULL) {
		pTail = pHead = pNode;
	} else {
		pTail->next = pNode;
		pTail = pNode;
	}
	p++;
    }
    return pHead;
}

void PrintList(Node *& pHead) 
{
    Node * p = pHead;
    int i = 0;
    while (p != NULL) {
	printf("Node %d: %s\n", i++, p->name);
	p = p->next;
    }
}

Node * SortList(Node *& pHead)
{
    Node *p = pHead;
    Node *p1, *pmin;
    p1 = pmin = p;
    if (!pHead || !pHead->next) {
    	return pHead;
    }
    while (p1->next) {
    	if (strcmp(pmin->name, p1->next->name) > 0) {
	    pmin = p1->next;
	    p1->next = p1->next->next;
    	}
	p1 = p1->next;
    }
    if (pmin != pHead) {
    	pmin->next = pHead;
	pHead = pmin;
    }
    p = pHead->next;
    Node *temp, *pTail;
    while ( p ) {
	p1 = pHead;
	while ( p1 != p && strcmp(p1->name, p->name) <= 0 ) {
	    temp = p1;
	    p1 = p1->next;
	}
	if ( p1 != p ) {
		
	}

	p = p->next;
    }
}

int main(int argc, const char *argv[])
{
	Node * pHead = NULL;
	pHead = MakeList(pHead, "Who are you?");
	printf("Making List...\n");
	printf("Now print the list:\n");
	PrintList(pHead);
	printf("Now reverse the list...\n");
	ReverseList(pHead);
	printf("Finished..\n");
	printf("Now print the list:\n");
	PrintList(pHead);
	return 0;
}

#include <iostream>
#include <string>

struct Node
{
    char name[3];
    Node *next;
    int value;
    Node(const char *p, int v = 0)
    {
	strcpy(name, p);
	value = value;
	next = NULL;
    }
};

Node * MakeList(Node *& pHead, const char *s, int value = 0) 
{
    char const *p = s;
    char name[3];
    Node * pNode, *pTail;
    while (*p != '\0') {
	name[0] = *p;
	name[1] = '\0';
	pNode = new Node(name, value);
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

void MergeList(Node *& pa, Node *& pb)
{
    Node * pha = pa;
    Node * phb = pb;
    Node * tempa = pha;
    Node * tempb = phb;
    while (pa != NULL && pb !=NULL ) {
	if (pha->value <= phb->value) {
	    while (pha && phb && pha->value <= phb->value) {
		tempa = pha;
		pha = pha->next;
	    }
	    tempa->next = phb;
	} else {
	    while (pha && phb && pha->value < phb->value) {
		tempb = phb;
		phb = phb->next;
	    }
	    tempb->next = pha;
	}
    }
}

Node * Recursive_MergeList(Node *& pha, Node *& phb)
{
    if ( pha == NULL ) return phb;
    if ( phb == NULL ) return pha;
    if ( pha->value <= phb->value ) {
    	pha->next = Recursive_MergeList(pha->next, phb);
	return pha;
    }
    if ( pha->value > phb->value ) {
    	phb->next = Recursive_MergeList(pha, phb->next);
	return phb;
    }
}

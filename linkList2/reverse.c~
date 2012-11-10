#include <stdio.h>

// Recursive version
void ReverseLinkList(Node *source, Node **Destination)
{
	assert(*Destination != NULL);
	if (source != NULL) {
		p = source->next;
		source->next = *Destination;
		*Destination = source;
		ReverseLinkList(p, Destination);
	}
}


// None Recursive version
void ReverseLinkList(Node *source, Node **Destination)
{
    while (source != NULL) {
    	p = source->next;
	source->next = *Destination;
	*Destination = source;
	source = p;
    }
}

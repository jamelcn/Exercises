Node * FindLCA(Node *root, int x, int y)
{
    Node * t = root;
    while (1) {
	if (t->data > x && t->data >y) {
	    t = t->left;
	} else if (t->data < x && t->data < y) {
	    t = t->right;
	} else {
	    return t;
	}
    }
}

Node* getLCA(Node *root, Node *x, Node *y)
{
	if (root == NULL) {
		return NULL;
	}
	if ( x == root || y == root ) {
		return root;
	}
	Node *pleft = getLCA(root->left, x, y);
	Node *pright = getLCA(root->right, x, y);
	if (pLeft == NULL) {
		return pright;
	} else if (pright == NULL) {
		return pleft;
	} else {
		return root;
	}

}

bool IsChildTree(Node * father, Node *son)
{
	if (father == NULL && son == NULL) {
		return true;
	}

	if (father == NULL && son != NULL) {
	    return false;
	}
	if (father != NULL && son == NULL) {
		return true;
	}

	if (father->data == son->data) {
		return IsChildTree(father->left, son->left) && IsChildTree(father->right, son->right);
	}

	if (IsChildTree(father->left, son)) {
		return true;
	}
	
	if (IsChildTree(father->right, son)) {
		return true;
	}
}

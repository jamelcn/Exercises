typedef struct Node {
	Node * left;
	Node * right;
	int maxLeft;
	int maxRight;
	char chValue;
}Node, *pNode;

int maxLen = 0;

void findMaxLength(Node * root)
{
	if (root == NULL) {
		return;
	}

	if (root->left == NULL) {
		root->maxLeft = 0;
	} else {
		findMaxLength(root->left);
	}

	if (root->right == NULL) {
		root->maxRight = 0;
	} else {
		findMaxLength(root->right);
	}

	if (root->left != NULL) {
		int tempMax = 0;
		if (root->left->maxLeft > root->left->maxRight) {
			tempMax = root->left->maxLeft;
		} else {
			tempMax = root->left->maxRight;
		}
		root->maxLeft = tempMax + 1;
	}

	if (root->right) {
		int tempMax = 0;
		if (root->right->maxLeft > root->right->maxRight) {
			tempMax = root->right->maxLeft;
		} else {
			tempMax = root->right->maxRight;
		}
		root->maxRight = tempMax + 1;
	}

	if (root->maxLeft + root->maxRight > maxLen) {
		maxLen = root->maxLeft + root->maxRight;
	}

}

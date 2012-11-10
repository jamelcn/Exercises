void ReBuild(char * pPreOrder, char * pInOrder, int nTreeLen, Node ** pRoot)
{
    if (pPreOrder == NULL || pInOrder == NULL) return;

    Node * temp = new Node;
    temp->data = *pPreOrder;
    temp->left = NULL;
    temp->right = NULL;

    if (*pRoot == NULL) {
	*pRoot = temp;
    }

    if (nTreeLen == 1) {
    	return;
    }

    char * pOrgInOrder = pInOrder;
    char * pLeftEnd = pInOrder;
    int nTempLen = 0;

    while (*pPreOrder != *pLeftEnd) {
    	/* code */
    }
}

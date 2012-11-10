bool GetNodePath(Node *pHead, Node *pNode, std::list<Node *>& path)
{
	if (pHead == pNode) {
		return true;
	}

	path.push_back(pHead);

	bool found = false;

	if (pHead->left != NULL) {
		found = GetNodePath(pHead->left, pNode, path);
	}

	if (!found && pHead->right) {
		found = GetNodePath(pHead->right, pNode, path);
	}

	if (!found) {
		path.pop_back();
	}
	return found;
}

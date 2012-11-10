int TreeHeight(Node * root, int & max_distance)
{
    if (root == NULL) {
    	max_distance = 0 ;
	return 0;
    }

    int left_height, right_height;

    if (root->left) {
	left_height  = TreeHeight(root->left, max_distance) + 1;
    } else {
    	left_height = 0;
    }

    if (root->right) {
    	right_height = TreeHeight(root->right, max_distance) + 1;
    } else {
    	right_height = 0;
    }

    int distance = left_height + right_height;
    if (max_distance < distance) {
    	max_distance = distance;
    }

    return (left_height > right_height ? left_height : right_height);
    
}

int TreeDiameter(Node * root) 
{
    int max_distance = 0;
    if (root) {
    	TreeHeight(root, max_distance);
    }
}

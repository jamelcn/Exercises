/*-----------------------------------------------------------------------------
 *  在二元树中找出和为某一值的所有路径 题目:输入一个整数和一棵二元树。 从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。 打印出和与输入整数相等的所有路径。
 *-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int data;                           /* value of node */
	TreeNode * left;                /* left child of node */
	TreeNode * right;               /* right chlid of node */
};

// 此函数的实现似乎并非是printPaths的功能
void printPaths(TreeNode * root, int sum)
{
	int path[MAX_HEIGHT];
	helper(root, sum, path, 0);
}

void helper(TreeNode * root, int sum, int path[], int top)
{
	path[top++] = root.data;
	sum -= root.data;
	if (root->left == NULL && root->right == NULL) {
		if (sum == 0) printPaths(path, top);
	} else {
		if (root->left != NULL) helper(root->left, sum, path, top);
		if (root->right != NULL) helper(root->right, sum, path, top);
	}
	top--;
	sum += root.data;
}

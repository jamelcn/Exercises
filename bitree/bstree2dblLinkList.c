
/*-----------------------------------------------------------------------------
 *  把二元查找树转变成排序的双向链表
 *  题目: 输入一棵二元查找树,将该二元查找树转换成一个排序的双向链表。 要求不能创建任何新的结点,只调整指针的指向。
 *   10 
 *  /   \
 *  6	 14 
 * / \  / \
 * 4 8 12 16
 *  转换成双向链表
 *  4=6=8=10=12=14=16。
 *-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

struct BSTreeNode {
	int m_nValue;                           /* value of node */
	BSTreeNode *m_pLeft;                    /* left child of node */
	BSTreeNode *m_pRight;                   /* right child of node */
};


/**
 * @param root The root node of the node
 * @return The head node of the converted list.
 */

BSTreeNode * treeToLinkedList(BSTreeNode * root) {
    BSTreeNode * head, * tail;
    helper(head, tail, root);
    return head;
}

void helper(BSTreeNode *& head, BSTreeNode *& tail, BSTreeNode *& root) 
{
    BSTreeNode *lt, *rh;
    if (root == NULL) {
    	head = NULL, tail = NULL;
	return;
    }
    helper(head, lt, root->m_pLeft);
    helper(head, rh, root->m_pRight);
    if (lt != NULL) {
    	lt->m_pRight = root;
	root->m_pLeft = lt;
    } else {
    	head = root;
    }

    if (rh != NULL) {
    	rh->m_pLeft = root;
	root->m_pRight = rh;
    } else {
    	tail = root;
    }
}



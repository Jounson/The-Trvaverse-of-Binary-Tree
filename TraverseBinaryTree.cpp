// TraverseBinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include<stdio.h>
using namespace std;

/* 二叉树结点的数据结构 */
typedef struct _BinaryTreeNode
{
	int _data;
	struct _BinaryTreeNode* _left;
	struct _BinaryTreeNode* _right;
}BinaryTreeNode;
/*
//先中后三种遍历的本质：压栈顺序没有什么不同的，所谓的先中后三种顺序，无非是访问根结点的时机不同而已
*/ 
// 二叉树的先序遍历函数/* 先序遍历的顺序：根->左->右 */
void preOrderTraverse(BinaryTreeNode* root)
{
	if (root)
	{	//递归的思想							
		printf("%d ", root->_data);/* 根 */
		preOrderTraverse(root->_left);/* 左 */
		preOrderTraverse(root->_right);/* 右 */
	}
}
// 二叉树的中序遍历函数/* 中序遍历的顺序：左->根->右 */
void midOrderTraverse(BinaryTreeNode* root)
{
	if (root)
	{	//递归的思想							
		midOrderTraverse(root->_left);/* 左 */
		printf("%d ", root->_data);/* 根 */
		midOrderTraverse(root->_right);/* 右 */
	}
}
// 二叉树的中序遍历函数/* 后序遍历的顺序：左->右->根 */
void postOrderTraverse(BinaryTreeNode* root)
{
	if (root)
	{	//递归的思想
		postOrderTraverse(root->_left);/* 左 */
		postOrderTraverse(root->_right);/* 右 */
		printf("%d ", root->_data);/* 根 */
	}
}

int main()
{
	BinaryTreeNode a, b, c, d, e, f;
	a._data = 1;
	b._data = 2;
	c._data = 3;
	d._data = 4;
	e._data = 5;
	f._data = 6;

	a._left = &b;/* a的左子树 */
	a._right = &c;/* a的右子树 */

	b._left = &d;/* b的左子树 */
	b._right = &e;/* b的右子树 */

	c._left = NULL;/* c的左子树 */
	c._right = &f;/* c的右子树 */

	d._left = d._right = e._left = e._right = f._left = f._right = NULL;

	/* 先序遍历 */
	cout << "先序: ";
	preOrderTraverse(&a);
	cout << endl;
	/* 中序遍历 */
	cout << "中序: ";
	midOrderTraverse(&a);
	cout << endl;
	/* 后序遍历 */
	cout << "后序: ";
	postOrderTraverse(&a);

	return 0;
}


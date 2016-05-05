//二叉搜索树与双向链表
//题目描述
//
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
//要求不能创建任何新的结点，只能调整树中结点指针的指向。

//思路
/*
二叉搜索树变成排序的列表，就必须通中序遍历二叉搜索树
解题的关键在于如何让当前结点跟前一个结点互连
设计一个可以返回前一个遍历过的结点的函数，把该结点返回就可互连
函数设计如下
void Convert(TreeNode* pRoot, TreeNode**pLast)
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* pLast = NULL;
		Convert(pRootOfTree, &pLast);

		while (pRootOfTree != NULL && pRootOfTree->left != NULL)
			pRootOfTree = pRootOfTree->left;

		return pRootOfTree;
	}

private:
	void Convert(TreeNode* pRoot, TreeNode**pLast)
	{
		if (!pRoot)
			return;
		if(pRoot->left !=NULL)
			Convert(pRoot->left, pLast);
		
		pRoot->left = *pLast;
		if(*pLast!=NULL)
			(*pLast)->right = pRoot;
		*pLast = pRoot;

		if (pRoot->right != NULL)
			Convert(pRoot->right, pLast);
	}
};


void Destory(TreeNode* root)
{
	if (!root)
		return;
	cout << root->val << " ";
	Destory(root->right);
	//Destory(root->right);
	delete root;
}
int main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);

	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);

	Solution a;
	//root = a.Convert(NULL);
	root = a.Convert(root);
	Destory(root);
	system("pause");
	return 0;
}



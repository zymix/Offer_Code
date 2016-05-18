//二叉树的深度
//题目描述
//
/*
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径
最长路径的长度为树的深度。
*/

//思路
/*
二叉树遍历

时间复杂度O（N）
空间复杂度O（1）
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
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
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int ldepth = 0;
		ldepth +=TreeDepth(pRoot->left)+1;
		int rdepth = 0; 
		rdepth +=TreeDepth(pRoot->right)+1;

		return ldepth > rdepth ? ldepth : rdepth;
	}
};

void DestoryTree(TreeNode* root)
{
	if (!root)
		return;
	DestoryTree(root->left);
	DestoryTree(root->right);
	delete root;
}

int main()
{
	Solution a;
	TreeNode* pRoot = new TreeNode(1);
	pRoot->left = new TreeNode(2);
	pRoot->right = new TreeNode(3);
	pRoot->left->left = new TreeNode(4);
	pRoot->left->right = new TreeNode(5);
	pRoot->left->left->left = new TreeNode(6);

	cout << a.TreeDepth(pRoot) << ' ';
	DestoryTree(pRoot);
	system("pause");
	return 0;
}



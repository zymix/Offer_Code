//平衡二叉树
//题目描述
//
/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

//思路
/*
二叉树遍历并保证左右子树的深度不超过1
思路简单，对编程技巧的考察，
需要设计一个
①知道当前左右子树的深度
②能知道当前子树是否符合平衡二叉树要求
的接口函数，因此有如下函数名
IsBalanced_Solution(TreeNode* pRoot,int &depth)

平均时间复杂度logN,
最坏时间复杂度N
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
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (!pRoot)
			return true;
		int depth=0;
		return IsBalanced_Solution(pRoot, depth);
	}
private:
	bool IsBalanced_Solution(TreeNode* pRoot,int &depth) {
		if (!pRoot)
		{
			depth = 0;
			return true;
		}
		int rdepth, ldepth;
		if (IsBalanced_Solution(pRoot->left, ldepth) &&
			IsBalanced_Solution(pRoot->right, rdepth))
		{
			int diff = ldepth - rdepth;
			if (-1<=diff&&diff <=1)
			{
				depth = 1 + (ldepth > rdepth ? ldepth : rdepth);
				return true;
			}
			else
				return false;
		}
		else
			return false;
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
	//pRoot->left->right->left = new TreeNode(6);

	cout << a.IsBalanced_Solution(pRoot) << ' ';
	DestoryTree(pRoot);
	system("pause");
	return 0;
}



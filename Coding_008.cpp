//二叉搜索树的第k个结点
//题目描述
//
//给定一颗二叉搜索树，请找出其中的第k大的结点。
//例如， 
//		 5 
//     / \ 
//   3   7
//  /\    /\
// 2 4  6 8
//k=3时，结点值为4

//思路
//二叉搜索树的规定是
//值比根结点小的结点做左子节点，值比根结点大的结点做右子节点
//所有利用中序遍历，并利用k来计数，即可求出答案

#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
	TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
	{
		if (!pRoot||k<=0)
			return NULL;
		TreeNode* ans = NULL;
		FindKNode(pRoot, k, &ans);
		return ans;
	}
private:
	void FindKNode(TreeNode* pRoot, unsigned int &k, TreeNode** ans)
	{
		if (!pRoot|| k<0)
			return ;
		FindKNode(pRoot->left, k, ans);
		if ((--k) == 0)
		{
			*ans = pRoot;
			return;
		}
		FindKNode(pRoot->right, k, ans);
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
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);

	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);	
	
	Solution a;
	cout << a.KthNode(root, 1)->val << " ";
	cout << a.KthNode(root, 2)->val << " ";
	cout << a.KthNode(root, 3)->val << " ";
	cout<<a.KthNode(root, 4)->val<<" ";
	cout << a.KthNode(root, 5)->val << " ";
	cout << a.KthNode(root, 6)->val << " ";
	cout << a.KthNode(root, 7)->val << " ";
	DestoryTree(root);
	system("pause");
	return 0;
}
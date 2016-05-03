//二叉树中和为某一值的路径
//题目描述
//
//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

//思路
/**
DFS深度优先遍历，注意回溯
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
private:
	vector<vector<int>> paths;
	vector<int>path;
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (!root)
			return paths;

		path.push_back(root -> val);
		FindPath(root->left, expectNumber - root->val);
		FindPath(root->right, expectNumber - root->val);
		if (root->left==NULL&&root->right==NULL&&0 == expectNumber - root->val)
		{//保证和为expectNumber 时，刚好到达叶子结点
			paths.push_back(path);
		}
		path.pop_back();//回溯
		return paths;
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
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(1);
	root->right = new TreeNode(1);

	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(1);

	Solution a;
	//auto results = a.FindPath(root, 2);
	auto results = a.FindPath(root, 3);
	for (auto res : results)
	{
		for (auto data : res)
			cout << data << " ";
		cout << endl;
	}

	DestoryTree(root);
	system("pause");
	return 0;
}


//树的子结构
//题目描述
//
//输入两颗二叉树A，B，判断B是不是A的子结构。

//思路


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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 != NULL&&pRoot2 != NULL)
		{
			return TravelTree(pRoot1, pRoot2);
		}
		return false;
	}

	bool TravelTree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot2)//B树为空，必然是A数的子树
			return true;
		if (!pRoot1)//B树不空，A树为空，必然不存在子树
			return false;

		if (pRoot1->val == pRoot2->val&&TravelTree(pRoot1->left, pRoot2->left) && TravelTree(pRoot1->right, pRoot2->right))
			return true;
		if (TravelTree(pRoot1->left, pRoot2) || TravelTree(pRoot1->right, pRoot2))
			return true;
		return false;
	}
};
int main()
{
	Solution a;
	TreeNode* h1 = new TreeNode(1);
	h1->left = new TreeNode(2);
	h1->right = new TreeNode(3);
	h1->right->right = new TreeNode(4);

	/*TreeNode* h2 = new TreeNode(3);
	h2->right = new TreeNode(4);*/
	TreeNode* h2 = NULL;

	std::cout << a.HasSubtree(h1,h2) << std::endl;


	system("pause");


	return 0;
}

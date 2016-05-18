//ƽ�������
//��Ŀ����
//
/*
����һ�ö��������жϸö������Ƿ���ƽ���������
*/

//˼·
/*
��������������֤������������Ȳ�����1
˼·�򵥣��Ա�̼��ɵĿ��죬
��Ҫ���һ��
��֪����ǰ�������������
����֪����ǰ�����Ƿ����ƽ�������Ҫ��
�Ľӿں�������������º�����
IsBalanced_Solution(TreeNode* pRoot,int &depth)

ƽ��ʱ�临�Ӷ�logN,
�ʱ�临�Ӷ�N
�ռ临�Ӷ�O��1��
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



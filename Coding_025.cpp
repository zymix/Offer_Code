//�����������
//��Ŀ����
//
/*
����һ�ö����������������ȡ�
�Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·��
�·���ĳ���Ϊ������ȡ�
*/

//˼·
/*
����������

ʱ�临�Ӷ�O��N��
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



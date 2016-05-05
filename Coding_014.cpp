//������������˫������
//��Ŀ����
//
//����һ�ö��������������ö���������ת����һ�������˫������
//Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

//˼·
/*
�������������������б��ͱ���ͨ�����������������
����Ĺؼ���������õ�ǰ����ǰһ����㻥��
���һ�����Է���ǰһ���������Ľ��ĺ������Ѹý�㷵�ؾͿɻ���
�����������
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



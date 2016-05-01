//�����������ĵ�k�����
//��Ŀ����
//
//����һ�Ŷ��������������ҳ����еĵ�k��Ľ�㡣
//���磬 
//		 5 
//     / \ 
//   3   7
//  /\    /\
// 2 4  6 8
//k=3ʱ�����ֵΪ4

//˼·
//�����������Ĺ涨��
//ֵ�ȸ����С�Ľ�������ӽڵ㣬ֵ�ȸ�����Ľ�������ӽڵ�
//�����������������������k�����������������

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
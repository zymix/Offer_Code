//�������к�Ϊĳһֵ��·��
//��Ŀ����
//
//����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·��
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

//˼·
/**
DFS������ȱ�����ע�����
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
		{//��֤��ΪexpectNumber ʱ���պõ���Ҷ�ӽ��
			paths.push_back(path);
		}
		path.pop_back();//����
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


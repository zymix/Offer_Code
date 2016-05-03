//�������´�ӡ������
//��Ŀ����
//
//�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

//˼·
/**
������ȱ���
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
	vector<int> PrintFromTopToBottom(TreeNode *root) {
		std::queue<TreeNode *>Q;
		std::vector<int> ans;
	
		if (!root)
			return ans;
		Q.push(root);

		while (!Q.empty())
		{
			TreeNode* temp = Q.front();
			
			ans.push_back(temp->val);
			if (temp->left != NULL)
				Q.push(temp->left);
			if (temp->right != NULL)
				Q.push(temp->right);
			
			Q.pop();
		}
		return ans;
	}
};

int main()
{
	
	Solution a;

	system("pause");
	return 0;
}
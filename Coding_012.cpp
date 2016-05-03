//二叉搜索树的后序遍历序列
//题目描述
//
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

//思路
/**
根据二叉搜索树定义，
根结点比左子树的所有结点大，比右子树的所有结点小，
根结点的子树也是二叉搜索树（递归定义）

后序遍历后，根结点为序列seq的最后一个数seq[end]，
则存在序列seq[start,mid]的所有数值小于根结点的值
存在序列seq[mid+1,end-1]的所有数值大于根结点的值
若其子序列也满足上述条件，作为二叉搜索树的后序遍历
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty)
			return false;
		int end = (int)sequence.size() - 1;
		
		return VerifySquenceOfBST(0, end, sequence);
	}
private:
	bool VerifySquenceOfBST(int start,int end, vector<int>& seq) {
		if (end <= start)
			return true;

		int mid = end - 1;
		while (seq[end] < seq[mid])
			mid--;
		for (int i = start; i < mid; i++)
		{
			if (seq[i] > seq[end])
				return false;
		}

		if (VerifySquenceOfBST(start, mid, seq) && VerifySquenceOfBST(mid + 1, end - 1, seq))
			return true;
		else
			return false;
	}
};

int main()
{
	vector<int> sequence{};
	vector<int> sequence1{ -1,2,1,4,3,6,8,7,5 };//true;
	vector<int> sequence2{ -1,2,4,1,3,6,8,7,5 };//false;
	vector<int> sequence3{ 2,-1,1,4,3,6,8,7,5 };//false;
	Solution a;
	std::cout << a.VerifySquenceOfBST(sequence);
	system("pause");
	return 0;
}
//两个数字的和等于S
//题目描述
//
/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S
如果有多对数字的和等于S，输出两个数的乘积最小的

对应每个测试案例，输出两个数，小的先输出。
*/

//思路
/*
由于是递增排序数组
令i=0，j=length(数组长度)-1;
此时num[i]和num[j]分别代表最大和最小的数
1.两值相加若大于S，则j-1，取更小的数
2.两值相加若小于S，则i+1，取更大的数
3.两值相加若等于S，则记录num[i]和num[j]，然后令i+1,j-1
不断重复上述步骤，直到i>=j


时间复杂度O（n）,
空间复杂度O（1）
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int i = 0;
		int j = array.size() - 1;
		vector<int> ans;
		while (i < j)
		{
			if (array[i] + array[j] == sum)
			{
				if (!ans.empty())
				{//输出两个数的乘积最小的
					if (ans[0] * ans[1]>array[i] * array[j])
					{//两个数，小的先输出
						ans.push_back(array[i]);
						ans.push_back(array[j]);
					}
				}
				else
				{
					ans.push_back(array[i]);
					ans.push_back(array[j]);
				}
				++i;
				--j;
			}
			else if (array[i] + array[j] > sum)
				--j;
			else
				++i;
		}
		return ans;
	}
};

int main()
{
	Solution a;
	vector<int> nums{ 1,2,3,4,5,6,7,8,9,10,11,15 };

	vector<int>ans{ a.FindNumbersWithSum(nums, 15) };
	for (auto a : ans)
		cout << a << ' ';
	system("pause");
	return 0;
}



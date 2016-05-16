//数组中的逆序对
//题目描述
//
/*
在数组中的两个数字，如果前面一个数字大于后面的数字，
则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。
*/

//思路
/*
假设数组为从降序时,逆序数对为n(n-1)，
当某一元素往前插入一个位置时，就出现一"顺序对"，那么逆序对总数-1
那么只需知道降序数组要各个元素要往前共插入多少个元素，才出现原数组的排列顺序就可以得到答案

关键在于求得原数组排列成降序要各个元素要往前共插入多少个元素

由此可以通过基于插入排序的归并排序求得插入次数
先把数组不断拆分成两份，至只剩一个元素
归并时统计往前共插入元素个数
归并为升序数组，避开以计算的元素个数
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;


class Solution {

public:
	int InversePairs(vector<int> data) {
		vector<int> temp;
		int sz = data.size();
		temp.resize(sz);

		return Merge(data, temp, 0, data.size() - 1);
	}
private:
	int Merge(vector<int>&data, vector<int>&temp, int start, int end)
	{
		if (end <= start)
			return 0;

		int count = 0;
		int middle = (start + end) / 2;
		count += Merge(data, temp, start, middle);
		count += Merge(data, temp, middle + 1, end);

		return count + MergeCmpared(data, temp, start, middle, end);
	}
	int MergeCmpared(vector<int>&data, vector<int>&temp, int start, int mid, int end)
	{
		int i = mid;
		int j = end;
		int k = end;
		int count = 0;
		while (i >= start&&j > mid)
		{
			if (data[i] > data[j])
			{
				count += k - i;//往前共插入元素个数
				temp[k--] = data[i--];
			}
			else
				temp[k--] = data[j--];
		}
		while (i >= start)
			temp[k--] = data[i--];
		while (j > mid)
			temp[k--] = data[j--];

		for (i = start; i <= end; i++)
			data[i] = temp[i];

		return count;
	}

};


int main()
{
	Solution a;
	vector<int> data{ 7,6,5 };
	cout << a.InversePairs(data) << ' ';
	system("pause");
	return 0;
}



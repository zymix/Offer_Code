//数字在排序数组中出现的次数
//题目描述
//
/*
统计一个数字在排序数组中出现的次数
*/

//思路
/*
这题等价于
在排序数组中查找一个数字k的第一次出现位置first
和数字k的最后一次出现位置last
出现数字k次数就是last-first+1;

很容易相处利用二分查找出任一个数字k的位置
然后往前往后统计k的个数

时间复杂度logN,
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
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return 0;
		int end = data.size() - 1;
		int first = GetFirstK(data, 0, end, k);
		int last = GetLastK(data, 0, end, k);

		if (first == last&&last == -1)
			return 0;
		return last - first + 1;
	}
private:
	int GetFirstK(vector<int>& data, int start, int end, int k) {
		if (start > end)
			return -1;

		int mid = (start + end) / 2;
		if (data[mid] < k)
			start = mid + 1;
		else if (data[mid]> k)
			end = mid - 1;
		else
		{
			if (mid == 0 || (mid > 0 && data[mid - 1] != k))
				return mid;
			else
				end = mid - 1;
		}
		return GetFirstK(data, start, end, k);
	}

	int GetLastK(vector<int>& data, int start, int end, int k) {
		if (start > end)
			return -1;

		int mid = (start + end) / 2;
		if (data[mid] < k)
			start = mid + 1;
		else if (data[mid]> k)
			end = mid - 1;
		else
		{
			int last = data.size() - 1;
			if (mid == last || (mid < last && data[mid + 1] != k))
				return mid;
			else
				start = mid + 1;
		}
		return GetLastK(data, start, end, k);
	}
};


int main()
{
	Solution a;
	//vector<int> nums{3};
	vector<int> nums{ 1,2,3,3,3,3,4,5 };
	cout << a.GetNumberOfK(nums, 3) << ' ';
	system("pause");
	return 0;
}



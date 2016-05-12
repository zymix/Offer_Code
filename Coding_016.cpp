//最小的K个数
//题目描述
//
//输入n个整数，找出其中最小的K个数。
//例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

//思路
/*
利用最大堆维护最小的k个数
遍历数组元素
当前元素比堆顶大的，则舍弃
当前元素比堆顶小的，则舍弃堆顶元素，加入当前元素
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <functional>
using namespace std;

typedef  multiset<int, greater<int>> intSet;
typedef  multiset<int, greater<int>>::iterator intIter;
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ans;
		if (k<=0|| k > input.size())
			return ans;

		intSet maxHeap;
		GetLeastNumbers(input, maxHeap, k);
		
		for (auto it = maxHeap.rbegin(); it != maxHeap.rend();++it)
			ans.push_back(*it);
		return ans;
	}
private:
	void GetLeastNumbers(vector<int> input, intSet& leastKNumbers, int k) {
		for (auto num : input)
		{
			if (leastKNumbers.size()<k)
				leastKNumbers.insert(num);
			else 
			{
				if (num < *leastKNumbers.begin())
				{
					leastKNumbers.erase(leastKNumbers.begin());
					leastKNumbers.insert(num);
				}
			}
		}
	}
};


int main()
{

	Solution a;
	vector<int>ans{ 1,5,4,6,2,7,3,8 };

	vector<int> data(std::move(a.GetLeastNumbers_Solution(ans,8)));
	for (auto a : data)
		cout << a << ' ';
	system("pause");
	return 0;
}



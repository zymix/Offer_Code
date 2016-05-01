//滑动窗口的最大值
//题目描述
//
//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
//例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
//那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}
//针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
// {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}
// {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

//思路
/**
用一个双端队列，队列第一个位置保存当前窗口的最大值，当窗口滑动一次
1.判断当前最大值是否过期
2.新增加的值从队尾开始比较，把所有比他小的值丢掉
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
	std::deque<int> Q;
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		size_t time = num.size();
		vector<int> ans;
		int k = size;//注意类型转换
		for (int i = 0; i < time;i++)
		{
			while (Q.size()&&num[Q.back()]<num[i])
				Q.pop_back();
			while (Q.size() &&Q.front()<=i-k)//若不做类型，i-size会转换为unsigned int类型而结果错误
				Q.pop_front();
			Q.push_back(i);
			if(k&&i+1>=k)
				ans.push_back(num[Q.front()]);
		}
		return ans;
	}
};

int main()
{
	vector<int> data{ 1,3,-1,-3,5,3,6,7 };
	Solution a;
	auto res = a.maxInWindows(data, 3);
	for (auto &ans :res)
		cout << ans << " ";

	system("pause");
	return 0;
}
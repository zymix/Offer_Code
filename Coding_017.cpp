//连续子数组的最大和
//题目描述
//
//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
//今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
//但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
//例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？

//思路
/*
对当前元素number[i]，有两种取的方案
1.加入连续子数组，得出连续子数组和
2.number[i]作为新子数组头元素
不难想出，若连续子数组和加上number[i]小于等于number[i]，则选择方案1
否则方案2

动态规划
设f(i)表示连续子数组最后一个元素为i的子数组累加和
		| number[i] , i为0或f(i-1)<=0
f(i)=	|
		| f(i-1)+number[i] , i不等于0且f(i-1)>0
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sz = array.size();
		if (sz == 0)
			return 0;

		int f[1000] = {0};
		int max = 0x80000000;//无穷小
		for (int i = 0; i < sz; ++i)
		{
			if (i == 0 || f[i - 1] < 0)
				f[i] = array[i];
			else
				f[i] = f[i - 1] + array[i];
			max = max > f[i] ? max : f[i];
		}
		return max;
	}
};


int main()
{

	Solution a;
	vector<int>ans{ -2,-8,-1,-5,-9 };

		cout << a.FindGreatestSumOfSubArray(ans) << ' ';
	system("pause");
	return 0;
}



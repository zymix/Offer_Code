//把数组排成最小的数
//题目描述
//
//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

//思路

//通过全排列思想启发
//通过一定的排序规则，则可把数组排成最小的数
//排序规则如下：
//数m和数n连接起来
//当mn<nm，则n>m，把n放在m的后面
//当mn>nm，则n<m，把n放在m的前面
//当mn=nm，则n=m，把n放在m的前面
//利用快排，重定义compare函数实现规则改写

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool compared(const string &n, const string &m)
{
	if ((n + m) <= (m + n))
	{
		return true;
	}
	return false;
}

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<string> numStrs;
		char temp[1000];
		for (int num : numbers)
		{
			sprintf_s(temp, "%d", num);
			numStrs.push_back(temp);
		}
		sort(numStrs.begin(), numStrs.end(),compared);
		
		string ans;
		for (string num : numStrs)
		{
			ans += num;
		}
		return ans;
	}

};


int main()
{

	Solution a;
	vector<int> test{ 9,2,11,3,32,321 };
	cout << a.PrintMinNumber(test) << ' ';
	system("pause");
	return 0;
}



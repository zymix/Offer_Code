//左旋转字符串
//题目描述
//
/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=“abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！
*/

//思路
/*
利用T(X)代表转置符号
XY ->YX
YX = T(T(YX))=T(T(X)T(Y))
	

把abcXYZdef看成两部分
abc XYZdef
-》cda fedZYX
-》XYZdef abc
-》XYZdefabc
也就是对需要循环左移（旋转）的字符串
反转前k位字符串
以及再反转剩下length - k位字符串
进行全部一次反转

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
	string LeftRotateString(string str, int n) {
		if (str.empty())
			return str;
		int len = str.length();
		if (len <= n||n<=0)
			return str;

		Reverse(str, 0, n-1);
		Reverse(str, n, len - 1);
		Reverse(str, 0, len - 1);
		
		return str;
	}
private:
	void Reverse(string& str, int start, int end)
	{
			while (start<end)
			{
				char temp = str[start];
				str[start] = str[end];
				str[end] = temp;
				++start;
				--end;
			}
	}
};


int main()
{
	Solution a;
	//vector<int> nums{3};
	string str{ "abcXYZdef" };
	cout << a.LeftRotateString(str,3) << ' ';
	system("pause");
	return 0;
}



//栈的压入、弹出序列
//题目描述
//
//输入两个整数序列，第一个序列表示栈的压入顺序
//请判断第二个序列是否为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序
//序列4，5,3,2,1是该压栈序列对应的一个弹出序列
//但4,3,5,1,2就不可能是该压栈序列的弹出序列。

//思路
/**
1.把pushV元素入辅助栈S
2.让辅助栈S栈顶popV序列依次比较
3.两者相同，则S栈顶出栈，并继续比较popV序列的下一元素，直到栈为空或两者不等
4.不两者相同则，重复执行1~3，直到pushV全部元素已入栈S
5.当pushV不存在没元素入栈S，判断栈S是否全部元素成功出栈，是则返回true，否则返回false
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
//			return false;
//
//		stack<int> s;
//		int ipush = 0, ipop = 0;
//		int size = (int)pushV.size();
//		while (ipush < size)
//		{
//			if (pushV[ipush] != popV[ipop])
//			{
//				if (s.size() && s.top() == popV[ipop])
//				{
//					s.pop();
//					++ipop;//相对于popV出栈
//				}
//				else
//				{
//					s.push(pushV[ipush]);
//					++ipush;//相对于popV入栈
//				}
//			}
//			else
//			{//相对于popV出栈
//				++ipush;
//				++ipop;
//			}
//		}
//		//pushV序列全部数经过入栈S或出栈S操作
//		//此时，popV剩下的序列只可能存在于栈S的出栈序列相同
//		while (s.size())
//		{
//			if (s.top() == popV[ipop])
//			{
//				s.pop();
//				++ipop;
//			}
//			else
//				return false;
//		}
//		return true;
//	}
//};

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0) return false;
		vector<int> stack;
		for (int i = 0, j = 0; i < pushV.size();) {
			stack.push_back(pushV[i++]);
			while (j < popV.size() && stack.back() == popV[j]) {
				stack.pop_back();
				j++;
			}
		}
		return stack.empty();
	}
};

int main()
{
	vector<int> v{ 1,2,3,4,5 };
	vector<int> u1{ 4,5,3,2,1 };
	vector<int> u2{ 4,3,5,1,2 };
	vector<int> u3{ 6,3,5,1,2 };
	vector<int> u4{ 1,2,3,5,4 };
	Solution a;

	cout<<a.IsPopOrder(v, u3);
	system("pause");
	return 0;
}
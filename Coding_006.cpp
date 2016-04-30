//包含min函数的栈
//题目描述
//
//定义栈的数据结构
//请在该类型中实现一个能够得到栈最小元素的min函数。
//push、pop、top、min均为O(1)

//思路
//多开辟一个辅助栈，不断存放比栈中最小元素还小的元素

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
private:
	std::stack<int> mStack, mStackMin;
public:
	void push(int value) {
		mStack.push(value);
		if(mStackMin.empty()|| value <= mStackMin.top())
			mStackMin.push(value);
	}
	void pop() {
		
		if (!mStackMin.empty() && mStack.top() == mStackMin.top())
			mStackMin.pop();
		mStack.pop();
	}
	int top() {
		return mStack.top();
	}
	int min() {
		return mStackMin.top();
	}
};
int main()
{
	Solution a;
	a.push(-1);
	a.push(2);
	a.push(-3);
	a.push(-3);
	std::cout << a.min()<<std::endl;
	a.pop();
	a.push(-4);
	std::cout << a.min() << std::endl;
	a.pop();
	std::cout << a.min() << std::endl;
	a.pop();
	std::cout << a.min() << std::endl;
	a.pop();
	std::cout << a.min() << std::endl;

	system("pause");


	return 0;
}

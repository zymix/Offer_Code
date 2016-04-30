//����min������ջ
//��Ŀ����
//
//����ջ�����ݽṹ
//���ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
//push��pop��top��min��ΪO(1)

//˼·
//�࿪��һ������ջ�����ϴ�ű�ջ����СԪ�ػ�С��Ԫ��

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

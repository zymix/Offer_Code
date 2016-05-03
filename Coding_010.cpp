//ջ��ѹ�롢��������
//��Ŀ����
//
//���������������У���һ�����б�ʾջ��ѹ��˳��
//���жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ�
//��������1,2,3,4,5��ĳջ��ѹ��˳��
//����4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ����������
//��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�

//˼·
/**
1.��pushVԪ���븨��ջS
2.�ø���ջSջ��popV�������αȽ�
3.������ͬ����Sջ����ջ���������Ƚ�popV���е���һԪ�أ�ֱ��ջΪ�ջ����߲���
4.��������ͬ���ظ�ִ��1~3��ֱ��pushVȫ��Ԫ������ջS
5.��pushV������ûԪ����ջS���ж�ջS�Ƿ�ȫ��Ԫ�سɹ���ջ�����򷵻�true�����򷵻�false
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
//					++ipop;//�����popV��ջ
//				}
//				else
//				{
//					s.push(pushV[ipush]);
//					++ipush;//�����popV��ջ
//				}
//			}
//			else
//			{//�����popV��ջ
//				++ipush;
//				++ipop;
//			}
//		}
//		//pushV����ȫ����������ջS���ջS����
//		//��ʱ��popVʣ�µ�����ֻ���ܴ�����ջS�ĳ�ջ������ͬ
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
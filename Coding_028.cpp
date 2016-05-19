//����ת�ַ���
//��Ŀ����
//
/*
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵�����
�������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
�ǲ��Ǻܼ򵥣�OK���㶨����
*/

//˼·
/*
����T(X)����ת�÷���
XY ->YX
YX = T(T(YX))=T(T(X)T(Y))
	

��abcXYZdef����������
abc XYZdef
-��cda fedZYX
-��XYZdef abc
-��XYZdefabc
Ҳ���Ƕ���Ҫѭ�����ƣ���ת�����ַ���
��תǰkλ�ַ���
�Լ��ٷ�תʣ��length - kλ�ַ���
����ȫ��һ�η�ת

ʱ�临�Ӷ�O��n��,
�ռ临�Ӷ�O��1��
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



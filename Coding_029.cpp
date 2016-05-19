//��ת����˳����
//��Ŀ����
//
/*
���磬��student. a am I����
�Ѿ��ӵ��ʵ�˳��ת�ˣ�
��ȷ�ľ���Ӧ���ǡ�I am a student.����
*/

//˼·
/*
����T(X)����ת�÷���
XY ->YX
YX = T(T(YX))=T(T(X)T(Y))
	
�������ַ�����ת
�ٶ����е����ٽ���һ�η�ת

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
	string ReverseSentence(string str) {
		if (str.empty())
			return str;
		int len = str.length();
		
		Reverse(str, 0, len - 1);
		int start = 0;
		for (int i = 0; i < len; ++i)
		{
			if (str[i] == ' ')
			{
				Reverse(str, start, i-1);
				while (str[++i] == ' ')
					;//�����������еĶ���ո�
				start = i;
			}
			else if (i == len - 1)
			{
				Reverse(str, start, i);
			}
		}
		
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
	string str{ "student.   a am I" };
	cout << a.ReverseSentence(str) << ' ';
	system("pause");
	return 0;
}



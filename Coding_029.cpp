//翻转单词顺序列
//题目描述
//
/*
例如，“student. a am I”。
把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。
*/

//思路
/*
利用T(X)代表转置符号
XY ->YX
YX = T(T(YX))=T(T(X)T(Y))
	
把整个字符串翻转
再对所有单词再进行一次反转

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
					;//过来掉单词中的多个空格
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



//第一个只出现一次的字符位置
//题目描述
//
//在一个字符串
//(1<=字符串长度<=10000，全部由字母组成)
//中找到第一个只出现一次的字符的位置。
//若为空串，返回-1。位置索引从0开始

//思路
/*
由于字符串全是字母组成
可以用一个长度为32的数组保存字母
用字母的大小顺序作为索引（哈希函数）
记下第一次出现的位置，当第二次出现设出现位置为零
最后遍历数组即可
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;


class Solution {
private:
	int position[60];
public:
	int FirstNotRepeatingChar(string str) {
		if (str.empty())
			return -1;
		
		int sz = str.size();
		memset(position, -1, sizeof(position));
		for (int i = 0; i < sz;i++)
		{
			int index = str[i]-'A';
			if(position[index]>=0)
				position[index] = -1;//已经出现
			else
				position[index] = i;//第一次出现
		}

		for (int i = 0; i < sz; i++)
		{
			int index = str[i] - 'A';
			if (position[index] >= 0)
			{
				cout << str[i] << endl;
				return position[index];
			}
		}
		return -1;
	}
};


int main()
{

	Solution a;

	cout << a.FirstNotRepeatingChar("AZaz") << ' ';
	system("pause");
	return 0;
}



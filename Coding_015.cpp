//全排列
//题目描述
//
//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
//结果请按字母顺序输出。 

//思路
/*
把字符串分成两部分，
一部分是已排列的，另一部分为未排列
已排列的部分的最后一个数，不断跟未排列部分的每一个数进行交换
深搜
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
private:
	vector<string> dataset;

public:
	vector<string> Permutation(string str)
	{
		if (str.empty())
			return dataset;
		sort(str.begin(),str.end());
		Permutation(str, str.size(), 0);
		return dataset;
	}
private:
	void Permutation(string str, int sz, int pos)//注意是按值传递
	{
		if (pos == sz)
		{
			dataset.push_back(str);
			return;
		}

		for (int i = pos; i < sz; ++i)
		{
			if (i != pos&&str[i] == str[pos])
				continue;//避免交换后字符串重复
			swap(str[i], str[pos]);
			Permutation(str, sz, pos + 1);

			//不复位可以保证字典序
			//swap(str[i], str[pos]);
		}

	}
};



int main()
{

	Solution a;

	vector<string> dataset(a.Permutation("1234"));

	for (auto ans : dataset)
		cout << ans << endl;
	system("pause");
	return 0;
}



//ȫ����
//��Ŀ����
//
//����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
//���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba�� 
//����밴��ĸ˳������� 

//˼·
/*
���ַ����ֳ������֣�
һ�����������еģ���һ����Ϊδ����
�����еĲ��ֵ����һ���������ϸ�δ���в��ֵ�ÿһ�������н���
����
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
	void Permutation(string str, int sz, int pos)//ע���ǰ�ֵ����
	{
		if (pos == sz)
		{
			dataset.push_back(str);
			return;
		}

		for (int i = pos; i < sz; ++i)
		{
			if (i != pos&&str[i] == str[pos])
				continue;//���⽻�����ַ����ظ�
			swap(str[i], str[pos]);
			Permutation(str, sz, pos + 1);

			//����λ���Ա�֤�ֵ���
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



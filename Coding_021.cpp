//��һ��ֻ����һ�ε��ַ�λ��
//��Ŀ����
//
//��һ���ַ���
//(1<=�ַ�������<=10000��ȫ������ĸ���)
//���ҵ���һ��ֻ����һ�ε��ַ���λ�á�
//��Ϊ�մ�������-1��λ��������0��ʼ

//˼·
/*
�����ַ���ȫ����ĸ���
������һ������Ϊ32�����鱣����ĸ
����ĸ�Ĵ�С˳����Ϊ��������ϣ������
���µ�һ�γ��ֵ�λ�ã����ڶ��γ��������λ��Ϊ��
���������鼴��
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
				position[index] = -1;//�Ѿ�����
			else
				position[index] = i;//��һ�γ���
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



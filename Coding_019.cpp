//�������ų���С����
//��Ŀ����
//
//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��

//˼·

//ͨ��ȫ����˼������
//ͨ��һ�������������ɰ������ų���С����
//����������£�
//��m����n��������
//��mn<nm����n>m����n����m�ĺ���
//��mn>nm����n<m����n����m��ǰ��
//��mn=nm����n=m����n����m��ǰ��
//���ÿ��ţ��ض���compare����ʵ�ֹ����д

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool compared(const string &n, const string &m)
{
	if ((n + m) <= (m + n))
	{
		return true;
	}
	return false;
}

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<string> numStrs;
		char temp[1000];
		for (int num : numbers)
		{
			sprintf_s(temp, "%d", num);
			numStrs.push_back(temp);
		}
		sort(numStrs.begin(), numStrs.end(),compared);
		
		string ans;
		for (string num : numStrs)
		{
			ans += num;
		}
		return ans;
	}

};


int main()
{

	Solution a;
	vector<int> test{ 9,2,11,3,32,321 };
	cout << a.PrintMinNumber(test) << ' ';
	system("pause");
	return 0;
}



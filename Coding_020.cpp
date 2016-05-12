//����
//��Ŀ����
//
//��ֻ��������2��3��5��������������Ugly Number����
//����6��8���ǳ�������14���ǣ���Ϊ����������7��
//ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������

//˼·
//���ڳ�������2,3,5���
//��������洢��֪��С�����˳��N������
//���ڵ�N+1������
//��������е�ĳ3������T2/T3/T5���ֱ����2��3��5
//��MIN��T2*2��MIN��T3*3��T5*5))
//��Ӧ��N+1��������T2��T3��T5��������һ������

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;


class Solution {
private:
	
public:
	int GetUglyNumber_Solution(int index) {
		int t2 = 1;
		int t3 = 1;
		int t5 = 1;
		unsigned int *uglyNum = new unsigned int[index+1];
		memset(uglyNum, 0, sizeof(unsigned int)*index);
		uglyNum[1] = 1;
		for (int i = 2; i <= index; i++)
		{
			int temp1 = uglyNum[t2] * 2;
			int temp2 = uglyNum[t3] * 3;
			int temp3 = uglyNum[t5] * 5;
			if (temp1 <= temp2&&temp1 <= temp3)
			{
				if (temp1 == temp2)
					++t3;
				if (temp1 == temp3)
					++t5;
				uglyNum[i] = temp1;
				++t2;
			}
			else if (temp2 <= temp3)
			{
				if (temp2 == temp3)
					++t5;
				uglyNum[i] = temp2;
				++t3;
			}
			else
			{
				uglyNum[i] = temp3;
				++t5;
			}
		}
		unsigned int ans = uglyNum[index];
		delete []uglyNum;
		return ans;
	}
};


int main()
{

	Solution a;

	cout << a.GetUglyNumber_Solution(10) << ' ';
	system("pause");
	return 0;
}



//��Ŀ����
//
//����һ���������飬ʵ��һ�����������������������ֵ�˳��
//ʹ�����е�����λ�������ǰ�벿�֣�
//���е�ż��λ��λ������ĺ�벿�֣�
//����֤������������ż����ż��֮������λ�ò���

//˼·�������������
/*
* 1.Ҫ�뱣֤ԭ�д�����ֻ��˳���ƶ������ڽ�����
* 2.i�������ұ������ҵ���һ��ż����
* 3.j��i+1��ʼ����ң�ֱ���ҵ���һ��������
* 4.��[i,...,j-1]��Ԫ���������һλ������ҵ�����������iλ�ã�Ȼ��i++��
* 5.�Kֹ�l����j������ʧ������Ҳ�Ҳ���������
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void reOrderArray(vector<int> &array)
	{
		int sz = array.size();
		for (int i = 0; i < sz; i++)
		{
			if ((array[i] & 0x1) == 0)//ż��
			{
				int j = i + 1;
				while (j < sz && (array[j] & 0x1) == 0)//����һ������
					++j;
				if (j == sz)
					return;//����������
				int temp = array[j];
				while (i < j)
				{
					array[j] = array[j - 1];
					--j;
				}
				array[j] = temp;
			}
		}
	}
};

int main()
{
	vector<int> arr = { 1,-5,9,-4,0,5,0,2,4,8,6,10,-2 };
	Solution a;
	a.reOrderArray(arr);
	int t = arr.size();
	for (int i = 0; i < t; i++)
		cout << arr[i] << " ";
	system("pause");

	return 0;
}
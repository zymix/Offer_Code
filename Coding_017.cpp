//���������������
//��Ŀ����
//
//HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
//��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
//����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
//����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��

//˼·
/*
�Ե�ǰԪ��number[i]��������ȡ�ķ���
1.�������������飬�ó������������
2.number[i]��Ϊ��������ͷԪ��
���������������������ͼ���number[i]С�ڵ���number[i]����ѡ�񷽰�1
���򷽰�2

��̬�滮
��f(i)��ʾ�������������һ��Ԫ��Ϊi���������ۼӺ�
		| number[i] , iΪ0��f(i-1)<=0
f(i)=	|
		| f(i-1)+number[i] , i������0��f(i-1)>0
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sz = array.size();
		if (sz == 0)
			return 0;

		int f[1000] = {0};
		int max = 0x80000000;//����С
		for (int i = 0; i < sz; ++i)
		{
			if (i == 0 || f[i - 1] < 0)
				f[i] = array[i];
			else
				f[i] = f[i - 1] + array[i];
			max = max > f[i] ? max : f[i];
		}
		return max;
	}
};


int main()
{

	Solution a;
	vector<int>ans{ -2,-8,-1,-5,-9 };

		cout << a.FindGreatestSumOfSubArray(ans) << ' ';
	system("pause");
	return 0;
}



//�����е������
//��Ŀ����
//
/*
�������е��������֣����ǰ��һ�����ִ��ں�������֣�
���������������һ������ԡ�
����һ�����飬�����������е�����Ե�������
*/

//˼·
/*
��������Ϊ�ӽ���ʱ,��������Ϊn(n-1)��
��ĳһԪ����ǰ����һ��λ��ʱ���ͳ���һ"˳���"����ô���������-1
��ôֻ��֪����������Ҫ����Ԫ��Ҫ��ǰ��������ٸ�Ԫ�أ��ų���ԭ���������˳��Ϳ��Եõ���

�ؼ��������ԭ�������гɽ���Ҫ����Ԫ��Ҫ��ǰ��������ٸ�Ԫ��

�ɴ˿���ͨ�����ڲ�������Ĺ鲢������ò������
�Ȱ����鲻�ϲ�ֳ����ݣ���ֻʣһ��Ԫ��
�鲢ʱͳ����ǰ������Ԫ�ظ���
�鲢Ϊ�������飬�ܿ��Լ����Ԫ�ظ���
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;


class Solution {

public:
	int InversePairs(vector<int> data) {
		vector<int> temp;
		int sz = data.size();
		temp.resize(sz);

		return Merge(data, temp, 0, data.size() - 1);
	}
private:
	int Merge(vector<int>&data, vector<int>&temp, int start, int end)
	{
		if (end <= start)
			return 0;

		int count = 0;
		int middle = (start + end) / 2;
		count += Merge(data, temp, start, middle);
		count += Merge(data, temp, middle + 1, end);

		return count + MergeCmpared(data, temp, start, middle, end);
	}
	int MergeCmpared(vector<int>&data, vector<int>&temp, int start, int mid, int end)
	{
		int i = mid;
		int j = end;
		int k = end;
		int count = 0;
		while (i >= start&&j > mid)
		{
			if (data[i] > data[j])
			{
				count += k - i;//��ǰ������Ԫ�ظ���
				temp[k--] = data[i--];
			}
			else
				temp[k--] = data[j--];
		}
		while (i >= start)
			temp[k--] = data[i--];
		while (j > mid)
			temp[k--] = data[j--];

		for (i = start; i <= end; i++)
			data[i] = temp[i];

		return count;
	}

};


int main()
{
	Solution a;
	vector<int> data{ 7,6,5 };
	cout << a.InversePairs(data) << ' ';
	system("pause");
	return 0;
}



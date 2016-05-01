//�������ڵ����ֵ
//��Ŀ����
//
//����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
//���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3��
//��ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}
//�������{2,3,4,2,6,2,5,1}�Ļ�������������6����
// {[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}
// {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��

//˼·
/**
��һ��˫�˶��У����е�һ��λ�ñ��浱ǰ���ڵ����ֵ�������ڻ���һ��
1.�жϵ�ǰ���ֵ�Ƿ����
2.�����ӵ�ֵ�Ӷ�β��ʼ�Ƚϣ������б���С��ֵ����
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
	std::deque<int> Q;
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		size_t time = num.size();
		vector<int> ans;
		int k = size;//ע������ת��
		for (int i = 0; i < time;i++)
		{
			while (Q.size()&&num[Q.back()]<num[i])
				Q.pop_back();
			while (Q.size() &&Q.front()<=i-k)//���������ͣ�i-size��ת��Ϊunsigned int���Ͷ��������
				Q.pop_front();
			Q.push_back(i);
			if(k&&i+1>=k)
				ans.push_back(num[Q.front()]);
		}
		return ans;
	}
};

int main()
{
	vector<int> data{ 1,3,-1,-3,5,3,6,7 };
	Solution a;
	auto res = a.maxInWindows(data, 3);
	for (auto &ans :res)
		cout << ans << " ";

	system("pause");
	return 0;
}
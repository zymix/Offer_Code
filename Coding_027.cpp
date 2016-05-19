//�������ֵĺ͵���S
//��Ŀ����
//
/*
����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S
����ж�����ֵĺ͵���S������������ĳ˻���С��

��Ӧÿ�����԰����������������С���������
*/

//˼·
/*
�����ǵ�����������
��i=0��j=length(���鳤��)-1;
��ʱnum[i]��num[j]�ֱ����������С����
1.��ֵ���������S����j-1��ȡ��С����
2.��ֵ�����С��S����i+1��ȡ�������
3.��ֵ���������S�����¼num[i]��num[j]��Ȼ����i+1,j-1
�����ظ��������裬ֱ��i>=j


ʱ�临�Ӷ�O��n��,
�ռ临�Ӷ�O��1��
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int i = 0;
		int j = array.size() - 1;
		vector<int> ans;
		while (i < j)
		{
			if (array[i] + array[j] == sum)
			{
				if (!ans.empty())
				{//����������ĳ˻���С��
					if (ans[0] * ans[1]>array[i] * array[j])
					{//��������С�������
						ans.push_back(array[i]);
						ans.push_back(array[j]);
					}
				}
				else
				{
					ans.push_back(array[i]);
					ans.push_back(array[j]);
				}
				++i;
				--j;
			}
			else if (array[i] + array[j] > sum)
				--j;
			else
				++i;
		}
		return ans;
	}
};

int main()
{
	Solution a;
	vector<int> nums{ 1,2,3,4,5,6,7,8,9,10,11,15 };

	vector<int>ans{ a.FindNumbersWithSum(nums, 15) };
	for (auto a : ans)
		cout << a << ' ';
	system("pause");
	return 0;
}



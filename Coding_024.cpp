//���������������г��ֵĴ���
//��Ŀ����
//
/*
ͳ��һ�����������������г��ֵĴ���
*/

//˼·
/*
����ȼ���
�����������в���һ������k�ĵ�һ�γ���λ��first
������k�����һ�γ���λ��last
��������k��������last-first+1;

�������ദ���ö��ֲ��ҳ���һ������k��λ��
Ȼ����ǰ����ͳ��k�ĸ���

ʱ�临�Ӷ�logN,
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
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return 0;
		int end = data.size() - 1;
		int first = GetFirstK(data, 0, end, k);
		int last = GetLastK(data, 0, end, k);

		if (first == last&&last == -1)
			return 0;
		return last - first + 1;
	}
private:
	int GetFirstK(vector<int>& data, int start, int end, int k) {
		if (start > end)
			return -1;

		int mid = (start + end) / 2;
		if (data[mid] < k)
			start = mid + 1;
		else if (data[mid]> k)
			end = mid - 1;
		else
		{
			if (mid == 0 || (mid > 0 && data[mid - 1] != k))
				return mid;
			else
				end = mid - 1;
		}
		return GetFirstK(data, start, end, k);
	}

	int GetLastK(vector<int>& data, int start, int end, int k) {
		if (start > end)
			return -1;

		int mid = (start + end) / 2;
		if (data[mid] < k)
			start = mid + 1;
		else if (data[mid]> k)
			end = mid - 1;
		else
		{
			int last = data.size() - 1;
			if (mid == last || (mid < last && data[mid + 1] != k))
				return mid;
			else
				start = mid + 1;
		}
		return GetLastK(data, start, end, k);
	}
};


int main()
{
	Solution a;
	//vector<int> nums{3};
	vector<int> nums{ 1,2,3,3,3,3,4,5 };
	cout << a.GetNumberOfK(nums, 3) << ' ';
	system("pause");
	return 0;
}



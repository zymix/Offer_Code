//��С��K����
//��Ŀ����
//
//����n���������ҳ�������С��K������
//��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��

//˼·
/*
��������ά����С��k����
��������Ԫ��
��ǰԪ�رȶѶ���ģ�������
��ǰԪ�رȶѶ�С�ģ��������Ѷ�Ԫ�أ����뵱ǰԪ��
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <functional>
using namespace std;

typedef  multiset<int, greater<int>> intSet;
typedef  multiset<int, greater<int>>::iterator intIter;
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ans;
		if (k<=0|| k > input.size())
			return ans;

		intSet maxHeap;
		GetLeastNumbers(input, maxHeap, k);
		
		for (auto it = maxHeap.rbegin(); it != maxHeap.rend();++it)
			ans.push_back(*it);
		return ans;
	}
private:
	void GetLeastNumbers(vector<int> input, intSet& leastKNumbers, int k) {
		for (auto num : input)
		{
			if (leastKNumbers.size()<k)
				leastKNumbers.insert(num);
			else 
			{
				if (num < *leastKNumbers.begin())
				{
					leastKNumbers.erase(leastKNumbers.begin());
					leastKNumbers.insert(num);
				}
			}
		}
	}
};


int main()
{

	Solution a;
	vector<int>ans{ 1,5,4,6,2,7,3,8 };

	vector<int> data(std::move(a.GetLeastNumbers_Solution(ans,8)));
	for (auto a : data)
		cout << a << ' ';
	system("pause");
	return 0;
}



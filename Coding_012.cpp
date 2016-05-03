//�����������ĺ����������
//��Ŀ����
//
//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
//����������Yes,�������No���������������������������ֶ�������ͬ��

//˼·
/**
���ݶ������������壬
�����������������н��󣬱������������н��С��
����������Ҳ�Ƕ������������ݹ鶨�壩

��������󣬸����Ϊ����seq�����һ����seq[end]��
���������seq[start,mid]��������ֵС�ڸ�����ֵ
��������seq[mid+1,end-1]��������ֵ���ڸ�����ֵ
����������Ҳ����������������Ϊ�����������ĺ������
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty)
			return false;
		int end = (int)sequence.size() - 1;
		
		return VerifySquenceOfBST(0, end, sequence);
	}
private:
	bool VerifySquenceOfBST(int start,int end, vector<int>& seq) {
		if (end <= start)
			return true;

		int mid = end - 1;
		while (seq[end] < seq[mid])
			mid--;
		for (int i = start; i < mid; i++)
		{
			if (seq[i] > seq[end])
				return false;
		}

		if (VerifySquenceOfBST(start, mid, seq) && VerifySquenceOfBST(mid + 1, end - 1, seq))
			return true;
		else
			return false;
	}
};

int main()
{
	vector<int> sequence{};
	vector<int> sequence1{ -1,2,1,4,3,6,8,7,5 };//true;
	vector<int> sequence2{ -1,2,4,1,3,6,8,7,5 };//false;
	vector<int> sequence3{ 2,-1,1,4,3,6,8,7,5 };//false;
	Solution a;
	std::cout << a.VerifySquenceOfBST(sequence);
	system("pause");
	return 0;
}
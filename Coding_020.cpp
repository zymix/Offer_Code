//丑数
//题目描述
//
//把只包含因子2、3和5的数称作丑数（Ugly Number）。
//例如6、8都是丑数，但14不是，因为它包含因子7。
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

//思路
//由于丑数是由2,3,5组成
//利用数组存储已知从小到大的顺序N个丑数
//对于第N+1个丑数
//则对于已有的某3个丑数T2/T3/T5，分别乘上2，3，5
//有MIN（T2*2，MIN（T3*3，T5*5))
//对应第N+1个丑数的T2或T3或T5，增加向一个丑数

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



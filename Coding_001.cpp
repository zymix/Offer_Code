//题目描述
//
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，
//所有的偶数位于位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变

//思路：插入排序变体
/*
* 1.要想保证原有次序，则只能顺次移动或相邻交换。
* 2.i从左向右遍历，找到第一个偶数。
* 3.j从i+1开始向后找，直到找到第一个奇数。
* 4.将[i,...,j-1]的元素整体后移一位，最后将找到的奇数放入i位置，然后i++。
* 5.終止條件：j向后查找失敗，再也找不到奇数。
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
			if ((array[i] & 0x1) == 0)//偶数
			{
				int j = i + 1;
				while (j < sz && (array[j] & 0x1) == 0)//找下一个奇数
					++j;
				if (j == sz)
					return;//不存在奇数
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
//两个链表的第一个公共结点
//题目描述
//
/*
输入两个链表，找出它们的第一个公共结点。
*/

//思路
/*
存在公共结点的链表类似'Y'型的数据结构
由于两个链表长度不一，
一个可能会比较长，另一个可能会比较短
但由于存在公共结点，两个链表的在第一个公共结点之后的部分
长度相同，
所以，

通过分别遍历两个链表，获取他们的长度len1，len2，设len1>len2
令len1长的链表先走len1-len2的长度，
然后再同时遍历两个链表（此时两链表的剩余长度均为len2）
当找到两个结点next的指针指向同一个结点时，即为公共结点

时间复杂度O（n+m）,空间复杂度O（1）
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;


struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
		int len1 = 0;
		ListNode* temp = pHead1;
		while (temp)
		{
			len1++;
			temp = temp->next;
		}

		int len2 = 0;
		temp = pHead2;
		while (temp)
		{
			len2++;
			temp = temp->next;
		}

		if (len1 > len2)
		{
			temp = pHead1;
			int sz = len1 - len2;
			while(sz)
			{
				pHead1 = pHead1->next;
				--sz;
			}
		}
		else
		{
			temp = pHead2;
			int sz = len2 - len1;
			while (sz)
			{
				pHead2 = pHead2->next;
				--sz;
			}
		}

		while (pHead1)
		{
			if (pHead1 == pHead2)
				return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return NULL;
	}
};


int main()
{
	Solution a;
	ListNode *list1 = new ListNode(5);
	list1->next = new ListNode(4);
	list1->next->next = new ListNode(30);

	ListNode *list2 = new ListNode(3);
	list2->next = list1->next->next;
	cout << a.FindFirstCommonNode(list1,list2)->val << ' ';
	system("pause");
	return 0;
}



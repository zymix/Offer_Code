//合并两个排序的链表
//题目描述
//
//输入两个单调递增的链表，输出两个链表合成后的链表
//当然我们需要合成后的链表满足单调不减规则。


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1)
			return pHead2;
		if (!pHead2)
			return pHead1;

		ListNode* pHead = NULL;
		ListNode* pNext = NULL;
		while (pHead1&&pHead2)
		{
			if (pHead1->val <= pHead2->val)
			{
				if (pHead == NULL)
					pHead = pNext = pHead1;
				else
				{
					pNext->next = pHead1;
					pNext = pNext->next;
				}
				pHead1 = pHead1->next;
			}
			else
			{
				if (pHead == NULL)
					pHead = pNext = pHead2;
				else
				{
					pNext->next = pHead2;
					pNext = pNext->next;
				}
				pHead2 = pHead2->next;
			}
		}


		if (pHead1 == NULL)
		{
			pNext->next = pHead2;
			return pHead;
		}
		else
		{
			pNext->next = pHead1;
			return pHead;
		}
	}
};
int main()
{
	ListNode* head1 = new ListNode(10);
	head1->next = new ListNode(20);
	head1->next->next = new ListNode(30);

	ListNode* head2 = new ListNode(0);
	head2->next = new ListNode(60);
	head2->next->next = new ListNode(80);
	Solution a;
	ListNode* head = a.Merge(head1, head2);

	while (head)
	{
		cout << head->val << " ";
		ListNode* temp = head->next;
		delete head;
		head = temp;
	}
	system("pause");


	return 0;
}

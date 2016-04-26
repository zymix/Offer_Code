//反转链表
//题目描述
//
//输入一个链表，反转链表后，输出链表的所有元素。

//思路
//一个指针h始终指向新链表的表头，另一个p始终指向原链表的表头
//不断取原链表的表头元素作为新链表的表头元素

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
	ListNode* ReverseList(ListNode* pHead)
	{
		/*if (!pHead || !pHead->next)
			return pHead;
		ListNode* pNext = pHead->next;
		ListNode* pTail = pNext->next;

		pHead->next = NULL;
		while (pNext)
		{
			pNext->next = pHead;
			pHead = pNext;

			pNext = pTail;
			if (pTail)
				pTail = pTail->next;
		}
		return pHead;*/

		ListNode* h = NULL;
		for (ListNode* p = pHead; p;)
		{
			ListNode* t = p->next;
			p->next = h;
			h = p;
			
			p = t;
		}
		return h;
	}
};

int main()
{
	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);

	Solution a;
	head = a.ReverseList(head);

	delete head->next->next;
	delete head->next;
	delete head;
	system("pause");

	return 0;
}

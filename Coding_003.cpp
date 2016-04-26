//��ת����
//��Ŀ����
//
//����һ��������ת�����������������Ԫ�ء�

//˼·
//һ��ָ��hʼ��ָ��������ı�ͷ����һ��pʼ��ָ��ԭ����ı�ͷ
//����ȡԭ����ı�ͷԪ����Ϊ������ı�ͷԪ��

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

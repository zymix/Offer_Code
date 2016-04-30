//链表中倒数第k个结点
//题目描述
//
//输入一个链表，输出该链表中倒数第k个结点。

//思路
//设两个指针，两个指针位置相差k，并一起移动
//当较前面的一指针到达倒数第1个结点时，
//另个一个指针便在倒数第k个结点时
//注意：k值小于1和大于链表长度的处理

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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (!pListHead)
			return pListHead;
		if(k<=0)
			return NULL;
		ListNode* pFront= pListHead;
		ListNode* pBack = pListHead;
		for (int i = k; i > 0; i--)
		{
			if (pFront == NULL)
				return NULL;
			pFront = pFront->next;
		}

		while (pFront != NULL)
		{
			pFront = pFront->next;
			pBack = pBack->next;
		}
		return pBack;
	}
};
int main()
{
	ListNode* head1 = new ListNode(10);
	//head1->next = new ListNode(20);
	//head1->next->next = new ListNode(30);

	Solution a;
	ListNode* node = a.FindKthToTail(head1, 1);
	cout << node->val;
	while (head1)
	{
		ListNode* temp = head1->next;
		delete head1;
		head1 = temp;
	}
	system("pause");


	return 0;
}

//�����е�����k�����
//��Ŀ����
//
//����һ����������������е�����k����㡣

//˼·
//������ָ�룬����ָ��λ�����k����һ���ƶ�
//����ǰ���һָ�뵽�ﵹ����1�����ʱ��
//���һ��ָ����ڵ�����k�����ʱ
//ע�⣺kֵС��1�ʹ��������ȵĴ���

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

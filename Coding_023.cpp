//��������ĵ�һ���������
//��Ŀ����
//
/*
�������������ҳ����ǵĵ�һ��������㡣
*/

//˼·
/*
���ڹ���������������'Y'�͵����ݽṹ
�������������Ȳ�һ��
һ�����ܻ�Ƚϳ�����һ�����ܻ�Ƚ϶�
�����ڴ��ڹ�����㣬����������ڵ�һ���������֮��Ĳ���
������ͬ��
���ԣ�

ͨ���ֱ��������������ȡ���ǵĳ���len1��len2����len1>len2
��len1������������len1-len2�ĳ��ȣ�
Ȼ����ͬʱ��������������ʱ�������ʣ�೤�Ⱦ�Ϊlen2��
���ҵ��������next��ָ��ָ��ͬһ�����ʱ����Ϊ�������

ʱ�临�Ӷ�O��n+m��,�ռ临�Ӷ�O��1��
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



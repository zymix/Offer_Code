#include <iostream>
#include <vector>
using namespace std;

  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
       }
 };

class Solution {
private:
    vector<int> ans;
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        if(!head)
            return ans;
        printListFromTailToHead(head->next);
        ans.push_back(head->val);
        return ans;
    }
};


int main()
{
    ListNode* head= new ListNode(10);
    head->next= new ListNode(30);
    head->next->next= new ListNode(40);
    Solution a;
    vector<int> ans = a.printListFromTailToHead(head);
    int sz = ans.size();
    for(int i=0;i<sz;i++)
        std::cout<<ans[i]<<" ";
    return 0;
}

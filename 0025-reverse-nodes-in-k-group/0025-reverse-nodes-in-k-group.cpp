/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class Pair{
        public:
        ListNode *head;
        ListNode *tail;
    };
    Pair reverse(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
        {
            Pair ans;
            ans.head=head;
            ans.tail=head;
            return ans;
        }
        Pair smallAns=reverse(head->next);
        smallAns.tail->next=head;
        head->next=NULL;
        Pair ans;
        ans.head=smallAns.head;
        ans.tail=head;
        return ans;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==0)
        {
            return head;
        }
        int cnt=k-1;
        ListNode *h1=head;
        ListNode *t1=head;
        while(cnt>0 && t1->next!=NULL)
        {
            cnt--;
            t1=t1->next;
        }
        if(cnt!=0)
        {
            return h1;
        }
        ListNode *h2=t1->next;
        t1->next=NULL;
        Pair smallAns=reverse(h1);
        h2=reverseKGroup(h2,k);
        smallAns.tail->next=h2;
        return smallAns.head;
        
        
    }
};
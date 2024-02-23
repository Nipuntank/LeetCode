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
    ListNode *midpoint(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *h1,ListNode *h2)
    {
        ListNode *head=new ListNode(0);
        ListNode *tail=head;
        while(h1!=NULL && h2!=NULL)
        {
            if(h1->val<h2->val)
            {
                tail->next=h1;
                tail=h1;
                h1=h1->next;
            }
            else{
                tail->next=h2;
                tail=h2;
                h2=h2->next;
            }

        }
        if(h1!=NULL)
        {
            tail->next=h1;
        }
        if(h2!=NULL)
        {
            tail->next=h2;
        }
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *lefthalf=head;
        ListNode *mid=midpoint(head);
        ListNode *righthalf=mid->next;
        mid->next=NULL;
        lefthalf=sortList(lefthalf);
        righthalf=sortList(righthalf);
        return merge(lefthalf,righthalf);
        
    }
};
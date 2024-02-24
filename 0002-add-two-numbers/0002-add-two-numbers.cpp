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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h=new ListNode(0);
        ListNode *t=h;
        int c=0;
        while(l1!=NULL && l2!=NULL)
        {
            int v=l1->val+l2->val+c;
            if(v>=10)
            {
             c=1;   
            }
            else{
                c=0;
            }
            ListNode *newNode=new ListNode(v%10);
            t->next=newNode;
            t=newNode;
            t->next=NULL;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int v=l1->val+c;
             if(v>=10)
            {
             c=1;   
            }
            else{
                c=0;
            }
            ListNode *newNode=new ListNode(v%10);
            t->next=newNode;
            t=newNode;
            t->next=NULL;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int v=l2->val+c;
             if(v>=10)
            {
             c=1;   
            }
            else{
                c=0;
            }
            ListNode *newNode=new ListNode(v%10);
            t->next=newNode;
            t=newNode;
            t->next=NULL;
            l2=l2->next;
        }
        if(c==1)
        {
            ListNode *newNode=new ListNode(c);
            t->next=newNode;
            t=newNode;
            t->next=NULL;
        }
        return h->next;
    }
};
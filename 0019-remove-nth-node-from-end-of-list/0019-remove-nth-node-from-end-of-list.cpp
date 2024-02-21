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
    int helper(ListNode *head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int c=helper(temp);
        int m=c-n;
        if(m==0)
        {
            ListNode *newNode=head->next;
            delete head;
            return newNode;
        }
        temp=head;
        while(temp!=NULL)
        {
            m--;
            if(m==0)
            {
                break;
            }
            
            temp=temp->next;
        }
        ListNode* delNode=temp->next;
        temp->next=temp->next->next;
        delete delNode;
        return head;
        
    }
};
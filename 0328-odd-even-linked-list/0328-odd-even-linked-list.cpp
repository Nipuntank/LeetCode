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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even=new ListNode(0);
        ListNode *etail=even;
        ListNode *odd=new ListNode(0);
        ListNode *otail=odd;
        int count=1;
        while(head!=NULL)
        {
            if(count%2==0)
            {
                etail->next=head;
                etail=head;
                head=head->next;
                etail->next=NULL;
            }
            else{
                otail->next=head;
                otail=head;
                head=head->next;
                otail->next=NULL;
            }
            count++;
        }
        otail->next=even->next;
        return odd->next;
        
    }
};
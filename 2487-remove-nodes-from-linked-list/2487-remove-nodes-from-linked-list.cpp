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
    ListNode* removeNodes(ListNode* head) {
        ListNode *temp=head;
        stack<ListNode *>st;
        while(temp!=NULL)
        {
            while(!st.empty() && st.top()->val<temp->val)
            {
                st.pop();
            }
            st.push(temp);
            temp=temp->next;
        }
        ListNode *prev=NULL;
        while(!st.empty())
        {
            temp=st.top();
            st.pop();
            temp->next=prev;
            prev=temp;
        }
        return temp;
    }
};
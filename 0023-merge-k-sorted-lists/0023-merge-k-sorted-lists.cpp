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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int>pq;
        for(auto it:lists)
        {
            while(it)
            {
                pq.push(it->val);
                it=it->next;
            }
        }
        ListNode *head=NULL;
        while(!pq.empty())
        {
            ListNode *newNode=new ListNode(pq.top());
            newNode->next=head;
            head=newNode;
            pq.pop();
        }
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp=head;
        unordered_map<ListNode *,int>mp;
        while(temp!=NULL)
        {
            mp[temp]=1;
            temp=temp->next;
            if(mp.find(temp)!=mp.end())
            {
                return true;
            }
        }
        return false;
    }
};
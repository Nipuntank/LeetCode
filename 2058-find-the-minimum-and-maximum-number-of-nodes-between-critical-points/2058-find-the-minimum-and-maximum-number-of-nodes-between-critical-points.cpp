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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev=head;
        head=head->next;
        int i=1,minDist=1e9,pi=-1e9,fi=-1;
        while(head->next)
        {
            if((prev->val<head->val && head->next->val<head->val) || 
               (prev->val>head->val && head->next->val>head->val))
            {
                if(pi!=-1e9)
                {
                    minDist=min(minDist,i-pi);
                }
                if(fi==-1)
                {
                    fi=i;
                }
                pi=i;
            }
            prev=head;
            head=head->next;
            i++;
        }
        if(minDist==1e9)
        {
            return {-1,-1};
        }
        return {minDist,pi-fi};
    }
};
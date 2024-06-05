class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<nums2.size();i++)
        {
            q.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            queue<int>q1=q;
            while(q1.front()!=nums1[i])
            {
                q1.pop();
            }
            q1.pop();
            while(q1.front()<nums1[i] && !q1.empty())
            {
                q1.pop();
            }
            if(q1.empty())
            {
                ans.push_back(-1);
            }
            else{
                ans.push_back(q1.front());
            }
        }
        return ans;
    }
};
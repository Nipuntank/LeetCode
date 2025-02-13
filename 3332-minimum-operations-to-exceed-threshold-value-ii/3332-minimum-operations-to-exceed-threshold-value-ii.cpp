class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        int cnt=0;
        while(!pq.empty())
        {
            long long x=pq.top();
            pq.pop();
            if(x>=k)
                return cnt;
            if(pq.empty())
                return cnt;
            long long y=pq.top();
            pq.pop();
            cnt++;
            long long ele=min(x,y)*2+max(x,y);
            pq.push(ele);
        }
        return -1;
    }
};
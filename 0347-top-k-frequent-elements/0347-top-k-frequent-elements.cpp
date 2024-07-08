class Solution {
public:
    struct compare{
        bool operator()(const pair<int,int>&a,const pair<int,int>&b)
        {
            return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(auto it:nums)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            pq.push({it.first,it.second});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
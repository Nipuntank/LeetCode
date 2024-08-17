class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;
        for(auto it:nums)
        {
            sum+=it;
            int mod=sum%k;
            if(mod<0)
            {
                mod+=k;
            }
            if(mp.find(mod)!=mp.end())
            {
                cnt+=mp[mod];
                
            }
            mp[mod]++;
        }
        return cnt;
        
    }
};
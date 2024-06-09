class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
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
                mp[mod]++;
            }
            else{
                mp[mod]++;
            }
        }
        return cnt;
    }
};
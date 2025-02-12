class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>mp(82,-1);
        int ans=-1;
        for(auto it:nums)
        {
            int temp=it,sum=0;
            while(temp)
            {
                sum+=(temp%10);
                temp=temp/10;
            }
            if(mp[sum]!=-1)
                ans=max(ans,mp[sum]+it);
            
            mp[sum]=max(mp[sum],it);
        }
        return ans;
    }
};
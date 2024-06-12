class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        if(n==1)
        {
            return nums[0];
        }
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int a=nums[i]+dp[i-2];
            int b=dp[i-1];
            dp[i]=max(a,b);
        }
        return dp[n-1];
    }
};
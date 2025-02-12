class Solution {
public:
    int helper(int i,int prev,vector<vector<int>>&dp,vector<int>&nums)
    {
        if(i==nums.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int take=0;
        if(prev==-1 || nums[i]>nums[prev])
            take= 1+helper(i+1,i,dp,nums);
        int notTake= helper(i+1,prev,dp,nums);
        return dp[i][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,-1,dp,nums);
    }
};


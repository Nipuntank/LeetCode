class Solution {
public:
    int helper(vector<int>&nums,vector<vector<int>>&dp,int i,int currSum,int sum,int t)
    {
        if(i==nums.size())
        {
            if(currSum==t)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][currSum+sum]!=-1)
        {
            return dp[i][currSum+sum];
        }
        int a=helper(nums,dp,i+1,currSum+nums[i],sum,t);
        int b=helper(nums,dp,i+1,currSum-nums[i],sum,t);
        return dp[i][currSum+sum]=a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
        return helper(nums,dp,0,0,sum,target);
    }
};
class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
        if(n<=3)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int a=helper(n-1,dp);
        int b=helper(n-2,dp);
        return dp[n]=a+b;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};
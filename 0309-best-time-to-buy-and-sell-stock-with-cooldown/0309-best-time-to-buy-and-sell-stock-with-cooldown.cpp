class Solution {
public:
    int helper(vector<int>&prices,vector<vector<int>>&dp,int i,int j)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int p;
        if(j==0)
        {
            p=max(helper(prices,dp,i+1,0),helper(prices,dp,i+1,1)-prices[i]);
        }
        if(j==1)
        {
            p=max(helper(prices,dp,i+1,1),helper(prices,dp,i+2,0)+prices[i]);
        }
        return dp[i][j]=p;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(prices,dp,0,0);
    }
};
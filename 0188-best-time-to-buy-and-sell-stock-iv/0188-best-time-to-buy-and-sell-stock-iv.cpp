class Solution {
public:
    int helper(vector<int>&prices,vector<vector<vector<int>>>&dp,int i,int j,int k)
    {
        if(i==prices.size() || k==0)
        {
            return 0;
        }
        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        int p;
        if(j==0)
        {
            p=max(helper(prices,dp,i+1,0,k),helper(prices,dp,i+1,1,k)-prices[i]);
        }
        if(j==1)
        {
            p=max(helper(prices,dp,i+1,1,k),helper(prices,dp,i+1,0,k-1)+prices[i]);
        }
        return dp[i][j][k]=p;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return helper(prices,dp,0,0,k);
    }
};
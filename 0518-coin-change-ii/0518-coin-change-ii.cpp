class Solution {
public:
    int helper(vector<int>&coins,vector<vector<int>>&dp,int i,int amt)
    {
        if(amt==0)
        {
            return 1;
        }
        if(i<0 || amt<0)
        {
            return 0;
        }
        if(dp[i][amt]!=-1)
        {
            return dp[i][amt];
        }
        int a=helper(coins,dp,i-1,amt);
        int b=helper(coins,dp,i,amt-coins[i]);
        return dp[i][amt]=(a+b);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins,dp,n-1,amount);
    }
};
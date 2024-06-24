class Solution {
public:
    int helper(vector<int>&coins,vector<vector<int>>&dp,int amt,int i)
    {
        if(i==0)
        {
            if(amt%coins[i]==0)
            {
                return amt/coins[i];
            }
            else{
                return 1e9;
            }
        }
        if(dp[i][amt]!=-1)
        {
            return dp[i][amt];
        }
        int a=helper(coins,dp,amt,i-1);
        int b=1e9;
        if(coins[i]<=amt)
        {
            b=1+helper(coins,dp,amt-coins[i],i);
        }
        return dp[i][amt]=min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
        {
            return 0;
        }
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= helper(coins,dp,amount,n-1);
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};
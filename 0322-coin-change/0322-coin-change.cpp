class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int j=0;j<amount+1;j++)
        {
            if(j%coins[0]==0)
            {
                dp[0][j]=j/coins[0];
            }
            else{
                dp[0][j]=1e9;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int a=dp[i-1][j];
                int b=1e9;
                if(coins[i]<=j)
                {
                    b=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(a,b);
            }
        }
        if(dp[n-1][amount]>=1e9)
        {
            return -1;
        }
        return dp[n-1][amount];
    }
};
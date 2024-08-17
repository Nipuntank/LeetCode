class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        int p;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(!j)
                {
                    p=max(dp[i+1][0],dp[i+1][1]-prices[i]);
                }
                else{
                    p=max(dp[i+1][1],dp[i+1][0]+prices[i]);
                }
                dp[i][j]=p;
            }
        }
        return dp[0][0];
    }
};
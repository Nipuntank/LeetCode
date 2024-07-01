class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                int p;
                if(j==0)
                {
                    p=max(dp[i+1][0],dp[i+1][1]-prices[i]);
                }
                if(j==1)
                {
                    p=max(dp[i+1][1],dp[i+2][0]+prices[i]);
                }
                dp[i][j]=p;
            }
        }
        return dp[0][0];
    }
};
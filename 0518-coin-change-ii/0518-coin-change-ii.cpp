class Solution {
public:
    
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amt+1,0));
        for(int i=0;i<amt+1;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=1;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<amt+1;j++)
            {
                int a=dp[i-1][j];
                int b=0;
                if(coins[i]<=j)
                {
                    b=dp[i][j-coins[i]];
                }
                dp[i][j]=a+b;
            }
        }
        return dp[n-1][amt];
    }
};
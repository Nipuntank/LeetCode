class Solution {
public:
    int helper(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int notj,int m,int n)
    {
        if(i==m)
        {
            return 0;
        }
        if(dp[i][notj]!=-1)
        {
            return dp[i][notj];
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(j==notj)
            {
                continue;
            }
            ans=min(ans,grid[i][j]+helper(grid,dp,i+1,j,m,n));
        }
        return dp[i][notj]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            ans=min(ans,grid[0][j]+helper(grid,dp,1,j,m,n));
        }
        return ans;
    }
};
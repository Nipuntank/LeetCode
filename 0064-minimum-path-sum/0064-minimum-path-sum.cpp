class Solution {
public:
    int helper(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j)
    {
        if(i==0 && j==0)
        {
            return grid[0][0];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a=1e9;
        int b=1e9;
        if(i>0)
        {
            a=grid[i][j]+helper(grid,dp,i-1,j);
        }
        if(j>0)
        {
            b=grid[i][j]+helper(grid,dp,i,j-1);
        }
        return dp[i][j]=min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(grid,dp,m-1,n-1);
    }
};
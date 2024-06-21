class Solution {
public:
    int helper(vector<vector<int>>&triangle,vector<vector<int>>&dp,int i,int j,int n)
    {
        if(i==n-1)
        {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a=helper(triangle,dp,i+1,j,n);
        int b=helper(triangle,dp,i+1,j+1,n);
        return dp[i][j]=triangle[i][j]+min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(triangle,dp,0,0,n);
    }
};
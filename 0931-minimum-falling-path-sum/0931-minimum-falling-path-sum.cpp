class Solution {
public:
    int helper(vector<vector<int>>&matrix,vector<vector<int>>&dp,int i,int j,int n)
    {
        if(j<0 || j>=n)
        {
            return 1e9;
        }
        if(i==0)
        {
            return matrix[0][j];
        }
        if(dp[i][j]!=1e9)
        {
            return dp[i][j];
        }
        int a=helper(matrix,dp,i-1,j-1,n);
        int b=helper(matrix,dp,i-1,j,n);
        int c=helper(matrix,dp,i-1,j+1,n);
        return dp[i][j]=matrix[i][j]+min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        int mini=1e9;
        for(int i=0;i<n;i++)
        {
            int ans=helper(matrix,dp,m-1,i,n);
            mini=min(mini,ans);
        }
        return mini;
    }
};
class Solution {
public:
    int helper(vector<vector<int>>&dp,int i,int j)
    {
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a=helper(dp,i-1,j);
        int b=helper(dp,i,j-1);
        return dp[i][j]=a+b;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(dp,m-1,n-1);
        
    }
};
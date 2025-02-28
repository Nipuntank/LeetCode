class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp=matrix;
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=INT_MAX;
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a=dp[i-1][j];
                int b=(j>0)?dp[i-1][j-1]:INT_MAX;
                int c=(j<n-1)?dp[i-1][j+1]:INT_MAX;
                dp[i][j]+=min(a,min(b,c));
            }
        }
        return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};
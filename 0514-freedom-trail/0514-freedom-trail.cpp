class Solution {
public:
    int helper(int i,int j,vector<vector<int>>&dp,string ring,string key,int m,int n)
    {
        if(j==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int step=INT_MAX;
        for(int k=0;k<m;k++)
        {
            if(key[j]==ring[k])
            {
                int count=min(abs(k-i),m-abs(k-i));
                step=min(step,count+helper(k,j+1,dp,ring,key,m,n));
            }
        }
        return dp[i][j]=step;
    }
    int findRotateSteps(string ring, string key) {
        int m=ring.size();
        int n=key.size();
        int i=0,j=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=helper(i,j,dp,ring,key,m,n)+n;
        return ans;
    }
};
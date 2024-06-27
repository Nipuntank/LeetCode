class Solution {
public:
    int mod=1e9+7;
    int helper(string s1,string s2,vector<vector<int>>&dp,int i,int j)
    {
        if(j<0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s1[i]==s2[j])
        {
            int a=helper(s1,s2,dp,i-1,j-1);
            int b=helper(s1,s2,dp,i-1,j);
            return dp[i][j]=(a+b)%mod;
        }
        else{
            return dp[i][j]=helper(s1,s2,dp,i-1,j);
        }
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(s,t,dp,m-1,n-1);
    }
};
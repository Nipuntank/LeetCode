class Solution {
public:
    int allStar(int i,string &p)
    {
        for(int j=0;j<=i;j++)
        {
            if(p[j]!='*')
                return 0;
        }
        return 1;
    }
    int helper(int i,int j,string &s,string &p,vector<vector<int>>&dp)
    {
        if(j<0)
            return i<0;
        if(i<0)
            return allStar(j,p);
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==p[j] || p[j]=='?')
            return dp[i][j]=helper(i-1,j-1,s,p,dp);
        if(p[j]=='*')
            return dp[i][j]=helper(i-1,j,s,p,dp)||helper(i,j-1,s,p,dp);
        return dp[i][j]=0;

    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,s,p,dp);
    }
};
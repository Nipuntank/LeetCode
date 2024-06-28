class Solution {
public:
    bool allStar(int i,string &p)
    {
        for(int j=0;j<=i;j++)
        {
            if(p[j]!='*')
            {
                return false;
            }
        }
        return true;
    }
    bool helper(string &s,string &p,vector<vector<int>>&dp,int i,int j)
    {
        if(j<0)
        {
            return i<0;
        }
        if(i<0)
        {
            return allStar(j,p);
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?')
        {
            return dp[i][j]=helper(s,p,dp,i-1,j-1);
        }
        if(p[j]=='*')
        {
            return dp[i][j]=helper(s,p,dp,i-1,j)|| helper(s,p,dp,i,j-1);    
        }    
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(s,p,dp,m-1,n-1);
    }
};
class Solution {
public:
    bool allStar(int i,string &p)
    {
        for(int j=1;j<=i;j++)
        {
            if(p[j-1]!='*')
            {
                return false;
            }
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0]=true;
        for(int j=1;j<n+1;j++)
        {
            dp[0][j]=allStar(j,p);
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
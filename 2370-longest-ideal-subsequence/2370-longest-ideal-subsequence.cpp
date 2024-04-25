class Solution {
public:
    int dp[100000][27];
    int helper(string &s,int k,int i,int prev)
    {
        if(i<0)
        {
            return 0;
        }
        if(dp[i][prev]!=-1)
        {
            return dp[i][prev];
        }
        char c=prev+'a';
        int take=0;
        if(abs(c-s[i])<=k || prev==26)
        {
            take=1+helper(s,k,i-1,s[i]-'a');
        }
        int notTake=helper(s,k,i-1,prev);
        return dp[i][prev]=max(take,notTake);
    }
    int longestIdealString(string s, int k) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        return helper(s,k,n-1,26);
    }
};
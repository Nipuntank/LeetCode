class Solution {
public:
    int helper(string &s1,string &s2,vector<vector<int>>&dp,int i,int j)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s1[i]==s2[j])
        {
            return dp[i][j]=1+helper(s1,s2,dp,i-1,j-1);
        }
        else{
            return dp[i][j]=max(helper(s1,s2,dp,i-1,j),helper(s1,s2,dp,i,j-1));
        }
    }
    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=helper(s,t,dp,n-1,n-1);
        return n-ans;
    }
};
class Solution {
public:
    int helper(string s1,string s2,vector<vector<int>>&dp)
    {
        int m=s1.size();
        int n=s2.size();
        if(m==0 || n==0)
        {
            return max(m,n);
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int ans=1e9;
        if(s1[0]==s2[0])
        {
            ans=helper(s1.substr(1),s2.substr(1),dp);
        }
        else{
            int a=1+helper(s1.substr(1),s2.substr(1),dp);
            int b=1+helper(s1.substr(1),s2,dp);
            int c=1+helper(s1,s2.substr(1),dp);
            ans=min(a,min(b,c));
        }
        return dp[m][n]=ans;
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(word1,word2,dp);
    }
};
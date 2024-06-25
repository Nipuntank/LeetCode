class Solution {
public:
    int helper(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
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
           return dp[i][j]=1+helper(i-1,j-1,s1,s2,dp); 
        }
        else{
            int b=helper(i-1,j,s1,s2,dp);
            int c=helper(i,j-1,s1,s2,dp);
            return dp[i][j]=max(b,c);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,text1,text2,dp);
    }
};
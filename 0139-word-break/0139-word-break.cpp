class Solution {
public:
    bool helper(int a,string s,set<string>&map,vector<int>&dp)
    {
        if(a==s.size())
        {
            return true;
        }
        if(dp[a]!=-1)
        {
            return dp[a];
        }
        for(int i=a;i<s.size();i++)
        {
            if(map.count(s.substr(a,i+1-a)) && helper(i+1,s,map,dp))
            {
                dp[a]=1;
                return true;
            }
        }
        return dp[a]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        set<string>map(wordDict.begin(),wordDict.end());
        return helper(0,s,map,dp);
    }
};
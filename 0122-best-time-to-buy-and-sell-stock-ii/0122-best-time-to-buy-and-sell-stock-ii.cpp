class Solution {
public:
    int helper(int i,int j,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(i==prices.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(!j)
        {
            return dp[i][j]=max(helper(i+1,0,prices,dp),helper(i+1,1,prices,dp)-prices[i]);
        }
        else{
            return dp[i][j]=max(helper(i+1,1,prices,dp),helper(i+1,0,prices,dp)+prices[i]);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(0,0,prices,dp);
    }
};
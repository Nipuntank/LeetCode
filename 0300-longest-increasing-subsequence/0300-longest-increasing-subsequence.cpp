class Solution {
public:
    int helper(vector<int>&nums,vector<vector<int>>&dp,int i,int j)
    {
        if(i==nums.size())
        {
            return 0;
        }
        if(dp[i][j+1]!=-1)
        {
            return dp[i][j+1];
        }
        int a=helper(nums,dp,i+1,j);
        int b=0;
        if(j==-1 || nums[j]<nums[i])
        {
            b=1+helper(nums,dp,i+1,i);
        }
        return dp[i][j+1]=max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(nums,dp,0,-1);
    }
};
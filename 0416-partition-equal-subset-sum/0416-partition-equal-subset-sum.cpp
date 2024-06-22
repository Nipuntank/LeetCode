class Solution {
public:
    bool helper(vector<int>&nums,vector<vector<int>>&dp,int sum,int i)
    {
        if(sum==0)
        {
            return true;
        }
        if(i==0)
        {
            return nums[i]==sum;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        int a=helper(nums,dp,sum,i-1);
        int b=0;
        if(nums[i]<=sum)
        {
            b=helper(nums,dp,sum-nums[i],i-1);
        }
        return dp[i][sum]= a||b;
    }
    bool canPartition(vector<int>& nums) {
       int sum=0;
        int n=nums.size();
        for(auto it:nums)
        {
            sum+=it;
        }
        if(sum%2==1)
        {
            return false;
        }
        else{
            sum=sum/2;
        }
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(nums,dp,sum,n-1);
    }
};
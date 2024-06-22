class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
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
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        if(nums[0]<=sum)
        {
            dp[0][nums[0]]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                int a=dp[i-1][j];
                int b=0;
                if(nums[i]<=j)
                {
                    b=dp[i-1][j-nums[i]];
                }
                dp[i][j]=a||b;
            }
        }
        return dp[n-1][sum];
    }
};
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int ans=INT_MIN;
        int sum=nums[0];
        ans=max(ans,sum);
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
                sum+=nums[i];
            else{
                sum=nums[i];
            }
            ans=max(ans,sum);
            
        }
        return ans;
    }
};
class Solution {
public:
    bool helper(vector<int>&nums,int mid,int k)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid)
            {
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        int ans;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(helper(nums,mid,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int l=0,r=n-1;
        vector<int>ans(n,0);
        for(int i=0,j=n-1;i<n && j>=0 ;i++,j--)
        {
            if(nums[i]<pivot)
            {
                ans[l++]=nums[i];
            }
            if(pivot<nums[j])
            {
                ans[r--]=nums[j];
            }
        }
        while(l<=r)
        {
            ans[l++]=pivot;
        }
        return ans;
    }
};
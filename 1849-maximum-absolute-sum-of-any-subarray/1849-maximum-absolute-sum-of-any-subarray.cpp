class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum=0,minSum=0;
        for(auto it:nums)
        {
            maxSum=max(0,maxSum+it);
            minSum=min(0,minSum+it);

        }
        cout<<maxSum<<minSum;
        return maxSum-minSum;
    }
};
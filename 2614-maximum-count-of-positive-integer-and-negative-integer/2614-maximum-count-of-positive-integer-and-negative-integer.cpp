class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCnt=helper(nums,0);
        int posCnt=nums.size()-helper(nums,1);
        return max(negCnt,posCnt);
    }
    int helper(vector<int>&nums,int target)
    {
        int l=0,r=nums.size()-1,res=nums.size();
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]<target)
            {
                l=mid+1;
            }
            else{
                res=mid;
                r=mid-1;
            }
        }
        return res;
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k=-1e9;
        for(auto it:nums)
        {
            k=max(k,it);
        }
        vector<int>count(3,0);
        for(auto it:nums)
        {
            count[it]++;
        }
        for(int i=1;i<=k;i++)
        {
            count[i]+=count[i-1];
        }
        vector<int>output(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            output[--count[nums[i]]]=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=output[i];
        }
    }
};
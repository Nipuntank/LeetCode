class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                cnt++;
                i++;
            }
        }
        return cnt*2==nums.size()?1:0;
    }
};
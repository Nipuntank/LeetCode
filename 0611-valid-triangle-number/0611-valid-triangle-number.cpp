class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int idx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                idx++;
            else
                break;
        }
        for(int i=idx;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int a=nums[i]+nums[j];
                auto it=lower_bound(nums.begin(),nums.end(),a)-(nums.begin()+j);
                ans+=(it-1);
            }
        }
        return ans;
    }
};
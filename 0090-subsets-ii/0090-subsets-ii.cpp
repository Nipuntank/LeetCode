class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums,vector<int>temp,int i)
    {
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++)
        {
            if(i!=j && nums[j]==nums[j-1])
            {
                continue;
            }
            temp.push_back(nums[j]);
            helper(nums,temp,j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        helper(nums,temp,0);
        return ans;
    }
};
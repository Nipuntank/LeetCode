class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums,vector<int>temp,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        helper(nums,temp,i+1);
        temp.push_back(nums[i]);
        helper(nums,temp,i+1);
        temp.pop_back();
         
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        helper(nums,temp,0);
        return ans;
    }
};
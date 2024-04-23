class Solution {
public:
    
    void helper(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int i,int n)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return ;
        }
        helper(nums,ans,temp,i+1,n);
        int a=nums[i];
        temp.push_back(a);
        helper(nums,ans,temp,i+1,n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        int s=0;
        helper(nums,ans,temp,s,n);
        return ans;
    }
};
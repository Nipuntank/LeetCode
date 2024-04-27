class Solution {
public:
    void helper(int i,int sum,vector<vector<int>>&ans,vector<int>&candidates,vector<int>&temp)
    {
        if(i==candidates.size())
        {
            if(sum==0)
            {
                ans.push_back(temp);
                
            }
            return ;
        }
        if(candidates[i]<=sum)
        {
            temp.push_back(candidates[i]);
            helper(i,sum-candidates[i],ans,candidates,temp);
            temp.pop_back();
        }
        helper(i+1,sum,ans,candidates,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,target,ans,candidates,temp);
        return ans;
        
    }
};
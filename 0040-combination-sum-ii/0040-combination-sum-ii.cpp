class Solution {
public:
    void helper(int i,int sum,vector<vector<int>>&ans,vector<int>&candidates,vector<int>temp)
    {
        if(sum==0)
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<candidates.size();j++)
        {
            if(candidates[j]>sum)
            {
                break;
            }
            if(j>i && candidates[j]==candidates[j-1])
            {
                continue;
            }
            temp.push_back(candidates[j]);
            helper(j+1,sum-candidates[j],ans,candidates,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(0,target,ans,candidates,temp);
        return ans;
    }
};
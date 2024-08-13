class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&candidates,int target,int i,vector<int>temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<candidates.size();j++)
        {
            if(target<candidates[j])
            {
                break;
            }
            if(j>i && candidates[j]==candidates[j-1])
            {
                continue;
            }
            temp.push_back(candidates[j]);
            helper(candidates,target-candidates[j],j+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,temp);
        return ans;
    }
};
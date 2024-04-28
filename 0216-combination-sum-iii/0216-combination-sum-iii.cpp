class Solution {
public:
    void helper(int i,int sum,int k,vector<vector<int>>&ans,vector<int>temp)
    {
        if(sum==0 && temp.size()==k)
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<=sum,j<=9;j++)
        {
            temp.push_back(j);
            helper(j+1,sum-j,k,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(1,n,k,ans,temp);
        return ans;
    }
};
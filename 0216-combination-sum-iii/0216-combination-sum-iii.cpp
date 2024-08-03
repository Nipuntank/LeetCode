class Solution {
public:
    vector<vector<int>>ans;
    void helper(int i,int k,int sum,vector<int>temp)
    {
        if(temp.size()==k && sum==0)
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<=9;j++)
        {
            temp.push_back(j);
            helper(j+1,k,sum-j,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        helper(1,k,n,temp);
        return ans;
    }
};
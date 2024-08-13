class Solution {
public:
    vector<vector<int>>ans;
    void helper(int n,int k,vector<int>temp,int i)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<=n;j++)
        {
            temp.push_back(j);
            helper(n,k,temp,j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        helper(n,k,temp,1);
        return ans;
    }
};
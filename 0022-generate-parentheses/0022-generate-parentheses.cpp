class Solution {
public:
    void helper(vector<string>&ans,string temp,int l,int r,int n)
    {
        if(l==r && r==n)
        {
            ans.push_back(temp);
            return ;
        }
        if(l<n)
        {
            temp.push_back('(');
            helper(ans,temp,l+1,r,n);
            temp.pop_back();
        }
        if(r<l)
        {
            temp.push_back(')');
            helper(ans,temp,l,r+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int l=0,r=0;
        vector<string>ans;
        string temp="";
        helper(ans,temp,l,r,n);
        return ans;
    }
};
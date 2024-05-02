class Solution {
public:
    bool isPalindrome(string st)
    {
        int s=0,e=st.size()-1;
        while(s<e)
        {
            if(st[s++]!=st[e--])
            return false;
        }
        return true;
    }
    void helper(int i,string s,vector<string>&temp,vector<vector<string>>&ans)
    {
        if(i==s.length())
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<s.length();j++)
        {
            if(isPalindrome(s.substr(i,j-i+1)))
            {
                temp.push_back(s.substr(i,j-i+1));
                helper(j+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        string str;
        helper(0,s,temp,ans);
        return ans;
    }
};
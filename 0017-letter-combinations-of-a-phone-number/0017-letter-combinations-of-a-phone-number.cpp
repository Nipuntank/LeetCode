class Solution {
public:
    void helper(int idx,string &temp,string digit,vector<string>&ans,vector<string>&map)
    {
        if(idx==digit.length())
        {
            if(temp.length())
            {
                ans.push_back(temp);
                
            }
            return ;
        }
        int num=digit[idx]-'0';
        string str=map[num];
        for(int i=0;i<str.length();i++)
        {
            temp.push_back(str[i]);
            helper(idx+1,temp,digit,ans,map);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string temp;
        helper(0,temp,digits,ans,map);
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        {
            return "";
        }
        string prefix=strs[0];
        for(auto it:strs)
        {
            while(it.find(prefix)!=0)
            {
                prefix=prefix.substr(0,prefix.length()-1);
            }
        }
        return prefix;
        
    }
};
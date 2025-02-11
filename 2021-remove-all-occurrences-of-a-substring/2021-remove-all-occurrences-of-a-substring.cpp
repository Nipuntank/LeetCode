class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int n=part.size();
        int t=part.back();
        for(auto it:s)
        {
            ans.push_back(it);
            if(it==t && ans.size()>=n)
            {
                if(ans.substr(ans.size()-n)==part)
                    ans.erase(ans.size()-n);
            }
        }
        return ans;
    }
};
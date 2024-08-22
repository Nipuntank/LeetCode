class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto it:strs)
        {
            string sorted=it;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
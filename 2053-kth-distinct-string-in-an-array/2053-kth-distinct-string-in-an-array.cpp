class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        string ans="";
        for(auto i:arr)
        {
            if(mp[i]==1)
            {
                ans=i;
                k--;
            }
            if(k==0)
            {
                return ans;
            }
        }
        return "";
    }
};
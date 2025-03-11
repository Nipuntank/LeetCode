class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int i=0;
        int n=s.size();
        int ans=0;
        for(int j=0;j<n;j++)
        {
            mp[s[j]]++;
            while(mp.size()==3)
            {
                ans+=n-j;
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
        }
        return ans;

    }
};
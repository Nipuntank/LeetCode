class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>minfreq(26,1e9);
        for(auto it:words)
        {
            vector<int>freq(26,0);
            for(auto j:it)
            {
                freq[j-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                minfreq[i]=min(minfreq[i],freq[i]);
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++)
        {
            while(minfreq[i]-->0)
            {
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
};
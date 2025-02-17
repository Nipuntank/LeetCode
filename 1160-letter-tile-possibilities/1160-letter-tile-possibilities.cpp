class Solution {
public:
    int helper(vector<int>&freq)
    {
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i])
            {
                freq[i]--;
                cnt+=1+helper(freq);
                freq[i]++;
            }
            
        }
        return cnt;
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26,0);
        for(char ch:tiles)
        {
            freq[ch-'A']++;
        }
        return helper(freq);
    }
};
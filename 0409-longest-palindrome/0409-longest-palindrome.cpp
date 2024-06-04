class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int odd=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]%2!=0)
            {
                odd++;
            }
            else{
                odd--;
            }
        }
        if(odd==0)
        {
            return s.size();
        }
        return s.size()-odd+1;
    }
};
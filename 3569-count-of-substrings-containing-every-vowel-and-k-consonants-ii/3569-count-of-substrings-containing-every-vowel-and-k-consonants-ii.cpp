class Solution {
public:
    int isVowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    long long helper(string &word,int k)
    {
        unordered_map<char,int>mp;
        int l=0;
        long long ans=0;
        int n=word.size();
        int cnt=0;
        for(int r=0;r<n;r++)
        {
            if(isVowel(word[r]))
                mp[word[r]]++;
            else
                cnt++;
            
            while(mp.size()==5 && cnt>=k)
            {
                ans+=n-r;
                if(isVowel(word[l]))
                {
                    mp[word[l]]--;
                    if(mp[word[l]]==0)
                        mp.erase(word[l]); 
                }
                else
                    cnt--;
                l++;
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return helper(word,k)-helper(word,k+1);
    }
};
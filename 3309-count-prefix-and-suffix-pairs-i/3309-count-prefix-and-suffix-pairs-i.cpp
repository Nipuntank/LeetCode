class Solution {
public:
    int helper(string str1,string str2)
    {
        int n1=str1.size(),n2=str2.size();
        if(n1>n2)
            return 0;
        return str2.substr(0,n1)==str1 && str2.substr(n2-n1)==str1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(helper(words[i],words[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};
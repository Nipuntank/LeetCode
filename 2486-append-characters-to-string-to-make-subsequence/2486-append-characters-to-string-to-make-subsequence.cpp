class Solution {
public:
    int appendCharacters(string s, string t) {
        int l1=s.size();
        int l2=t.size();
        int i=0,j=0;
        while(i<l1 && j<l2)
        {
            if(s[i]==t[j])
            {
                j++;
            }
            i++;
        }
        return l2-j;
    }
};
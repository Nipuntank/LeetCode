class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        int i=0;
        int n=s.size();
        while(i<s.size())
        {
            temp="";
            while(i<n && s[i]!=' ')
            {
                temp+=s[i];
                i++;
            }
            while(i<n && s[i]==' ')
            {
                i++;
            }
            if(!temp.empty())
            {
                if(ans.empty())
                {
                    ans+=temp;
                }
                else{
                    ans=temp+' '+ans;
                }
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                cnt++;
            }
            else if(s[i]==')')
            {
                ans=max(ans,cnt);
                cnt--;
            }
        }
        return ans;
    }
};
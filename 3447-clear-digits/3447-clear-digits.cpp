class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        if(n==0)
            return "";
        stack<char>st;
        int i=0;
        while(i<n)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                st.push(s[i]);
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            i++;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
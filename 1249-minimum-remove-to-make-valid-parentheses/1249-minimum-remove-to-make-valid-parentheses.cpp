class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push({s[i],i});
            }
            else if(s[i]==')')
            {
                if( !st.empty() && st.top().first=='(')
                {
                    st.pop();
                }
                else{
                    st.push({s[i],i});
                }
            }
            else{
                continue;
            }
        }
        while(!st.empty())
        {
            int i=st.top().second;
            s.erase(s.begin()+i);
            st.pop();
        }
        return s;
    }
};
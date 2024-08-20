class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            int c=s[i];
            if(c=='(' || c=='{' || c=='[')
            {
                st.push(c);
            }
            if(st.empty() && (c==')' || c==']' || c=='}'))
            {
                return false;
            }
            if(c==')')
            {
                if(st.top()=='(')
                {
                    st.pop();
                }
                else return false;
            }
            else if(c=='}')
            {
                if(st.top()=='{')
                {
                    st.pop();
                }
                else return false;
            }
            else if(c==']')
            {
                if(st.top()=='[')
                {
                    st.pop();
                }
                else return false;
            }
        }
        while(!st.empty())
        {
            return false;
        }
        return true;
    }
};
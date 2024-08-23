class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char opr='+';
        int num=0;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(isdigit(c))
            {
                num=num*10+(c-'0');
            }
            if((!isdigit(c) && c!=' ') || i==s.size()-1)
            {
                if(opr=='+')
                {
                    st.push(num);
                }
                else if(opr=='-')
                {
                    st.push(-num);
                }
                else if(opr=='*')
                {
                    int a=st.top()*num;
                    st.pop();
                    st.push(a);
                }
                else if(opr=='/')
                {
                    int a=st.top()/num;
                    st.pop();
                    st.push(a);
                }
                opr=c;
                num=0;
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
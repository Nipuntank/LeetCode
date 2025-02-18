class Solution {
public:
    string smallestNumber(string pattern) {
        string ans="";
        int n=pattern.size();
        stack<int>st;
        int num=1;
        for(auto it:pattern)
        {
            if(it=='D')
            {
                st.push(num);
                num++;
            }
            else{
                st.push(num);
                num++;
                while(!st.empty())
                {
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty())
        {
            ans+=to_string(st.top());
            st.pop();
        }
        return ans;
    }
};
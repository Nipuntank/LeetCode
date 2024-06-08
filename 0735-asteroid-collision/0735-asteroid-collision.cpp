class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto it:asteroids)
        {
            if(it>0)
            {
                st.push(it);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<-it)
                {
                    st.pop();
                }
                if(st.empty() || st.top()<0)
                {
                    st.push(it);
                }
                if(!st.empty() && st.top()==-it)
                {
                    st.pop();
                }
            }
        }
        int n=st.size();
        vector<int>ans(n,0);
        while(!st.empty())
        {
            ans[--n]=st.top();
            st.pop();
        }
        return ans;
    }
};
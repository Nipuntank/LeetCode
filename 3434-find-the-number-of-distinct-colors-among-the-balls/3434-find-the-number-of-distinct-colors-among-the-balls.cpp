class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int,int>ball_color;
        unordered_map<int,int>color;
        for(int i=0;i<queries.size();i++)
        {
            int b=queries[i][0];
            int c=queries[i][1];
            if(ball_color.count(b))
            {
                color[ball_color[b]]--;
                if(color[ball_color[b]]==0)
                {
                    color.erase(ball_color[b]);
                }
            }
            ball_color[b]=c;
            color[c]++;
            ans.push_back(color.size());

        }
        return ans;
    }
};
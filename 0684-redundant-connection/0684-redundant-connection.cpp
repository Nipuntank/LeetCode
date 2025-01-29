class Solution {
public:
    int find(vector<int>&dsuf,int v)
    {
        if(dsuf[v]==-1)
            return v;
        return dsuf[v]=find(dsuf,dsuf[v]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>dsuf(n+1,-1);
        for(auto it:edges)
        {
            int x=find(dsuf,it[0]);
            int y=find(dsuf,it[1]);
            if(x==y)
                return it;
            else
                dsuf[x]=y;
        }
        return {0,0};
    }
};
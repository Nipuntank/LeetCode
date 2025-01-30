class Solution {
public:
    bool dfs(int i,vector<int>adj[],vector<int>&color,int n)
    {
        if(color[i]==-1)
            color[i]=1;
        for(auto it:adj[i])
        {
            if(color[it]==-1)
            {
                color[it]=color[i]-1;
                if(!dfs(it,adj,color,n))
                    return false;
            }
            else if(color[it]==color[i])
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n];
        for(auto it:dislikes)
        {
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        vector<int>color(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(i,adj,color,n))
                    return false;
            }
        }
        return true;
    }
};
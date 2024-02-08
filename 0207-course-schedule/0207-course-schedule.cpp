class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathVis,vector<int>&ans)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,pathVis,ans);
            }
            else if(pathVis[it])
            {
                return ;
            }
        }
        pathVis[node]=0;
        ans.push_back(node);
        return ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans;
        vector<int>vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,pathVis,ans);
            }
        }
        if(numCourses==ans.size())
        {
            return true;
        }
        return false;
    }
};
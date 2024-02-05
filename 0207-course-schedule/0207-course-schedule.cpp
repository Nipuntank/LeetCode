class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&visited,stack<int>&st,vector<int>dfsVis)
    {
        visited[node]=1;
        dfsVis[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited,st,dfsVis);
            }
            if(dfsVis[it])
            {
                return ;
            }
        }
        dfsVis[node]=0;
        st.push(node);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        vector<int>dfsVis(numCourses,0);
        stack<int>st;
        vector<int> adj[numCourses];
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,st,dfsVis);
            }
        }
        if(st.size()==numCourses)
        {
            return true;
        }
        return false;
    }
};
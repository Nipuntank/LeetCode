class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<pair<int,int>,int>>q;
        q.push({{src,0},0});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty())
        {
            int node=q.front().first.first;
            int cost=q.front().first.second;
            int stop=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int d=it.second;
                if(d+cost<dist[adjNode] && stop<=k)
                {
                    q.push({{adjNode,d+cost},stop+1});
                    dist[adjNode]=d+cost;
                }
            }
        }
        if(dist[dst]==1e9)
        {
            return -1;
        }
        return dist[dst];
    }
};
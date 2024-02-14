class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=int(1e9+7);
        vector<pair<long long,long long>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,LLONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
        q.push({0,0});
        while(!q.empty())
        {
            long long node=q.top().second;
            long long cost=q.top().first;
            q.pop();
            if (dist[node] < cost)
                continue;
            for(auto it:adj[node])
            {
                long long adjNode=it.first;
                long long d=it.second;
                if(d+cost<dist[adjNode])
                {
                    dist[adjNode]=d+cost;
                    q.push({d+cost,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(d+cost==dist[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
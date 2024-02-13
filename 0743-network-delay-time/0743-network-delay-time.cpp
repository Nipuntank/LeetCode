class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>time(n+1,1e9);
        time[k]=0;
        queue<pair<int,int>>q;
        q.push({k,0});
        while(!q.empty())
        {
            int node=q.front().first;
            int cost=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int c=it.second;
                if(c+cost<time[adjNode])
                {
                    q.push({adjNode,c+cost});
                    time[adjNode]=c+cost;
                }
            }
        }
        int minTime=-1e9;
        for(int i=1;i<=n;i++)
        {
            if(time[i]==1e9)
            {
                return -1;
            }
            minTime=max(minTime,time[i]);
        }
        return minTime;
    }
};
class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void bfs(vector<vector<int>>&grid,vector<vector<int>>&dis,int n)
    {
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int s=dis[r][c];
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && dis[nr][nc]>1+s)
                {
                    dis[nr][nc]=1+s;
                    q.push({nr,nc});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        {
            return 0;
        }
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        bfs(grid,dis,n);
        vector<vector<int>>vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({dis[0][0],{0,0}});
        
        while(!pq.empty())
        {
            int s=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==n-1)
            {
                return s;
            }
            vis[i][j]=1;
            for(int k=0;k<4;k++)
            {
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n &&!vis[ni][nj])
                {
                    int newSafe=min(s,dis[ni][nj]);
                    pq.push({newSafe,{ni,nj}});
                    vis[ni][nj]=1;
                }
            }
        }
        return -1;
    }
};
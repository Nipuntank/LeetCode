class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int ii,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,int m,int n,queue<pair<int,pair<int,int>>>&q)
    {
        if(!vis[ii][j])
        {
            vis[ii][j]=1;
            q.push({0,{ii,j}});
            for(int i=0;i<4;i++)
            {
                int ni=ii+dx[i];
                int nj=j+dy[i];
                if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && grid[ni][nj]==1)
                {
                    dfs(ni,nj,vis,grid,m,n,q);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>>q;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1 && cnt<1)
                {
                    dfs(i,j,vis,grid,m,n,q);
                    cnt++;
                }
            }
        }
        int ans=1e9;
        while(!q.empty())
        {
            int d=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]==0)
                {
                    vis[nx][ny]=1;
                    q.push({d+1,{nx,ny}});
                }
                else if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]==1)
                {
                    ans=min(ans,d);
                }
            }
        }
        return ans;
    }
    
};
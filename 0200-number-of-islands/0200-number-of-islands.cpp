class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void bfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis,int m,int n)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            vis[row][col]=1;
            for(int k=0;k<4;k++)
            {
                int nrow=row+dx[k];
                int ncol=col+dy[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    bfs(i,j,grid,vis,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};
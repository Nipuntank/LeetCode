class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis,int m,int n)
    {
        int a=grid[r][c];
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]>0)
            {
                a+=dfs(nr,nc,grid,vis,m,n);
                
            }
        }
        return a;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0 && !vis[i][j])
                {
                    ans=max(ans,dfs(i,j,grid,vis,m,n));
                }
            }
        }
        return ans;
    }
};
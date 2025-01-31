class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int dfs(int r,int c,vector<vector<int>>&grid,int id,int n)
    {
        grid[r][c]=id;
        int cnt=1;
        for(int i=0;i<4;i++)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
            {
                cnt+=dfs(nr,nc,grid,id,n);
            }
        }
        return cnt;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>mp;
        int id=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    mp[id]=dfs(i,j,grid,id,n);
                    id++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int>s;
                    for(int k=0;k<4;k++)
                    {
                        int ni=i+dx[k];
                        int nj=j+dy[k];
                        if(ni>=0 && ni<n && nj>=0 && nj<n)
                        {
                            s.insert(grid[ni][nj]);
                        }
                    }
                    int cnt=1;
                    for(auto it:s)
                    {
                        cnt+=mp[it];
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        return ans==0?n*n:ans;
    }
};
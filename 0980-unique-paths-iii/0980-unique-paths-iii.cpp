class Solution {
public:
    int dfs(vector<vector<int>>&grid,int x,int y,int cnt)
    {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==-1)
        {
            return 0;
        }
        if(grid[x][y]==2)
        {
            return cnt==-1 ? 1 : 0;
        }
        cnt--;
        grid[x][y]=-1;
        int a=dfs(grid,x-1,y,cnt)+dfs(grid,x,y+1,cnt)+dfs(grid,x+1,y,cnt)+dfs(grid,x,y-1,cnt);
        cnt++;
        grid[x][y]=0;
        return a;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr=0,sc=0,cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    sr=i;
                    sc=j;
                }
                if(grid[i][j]==0)
                {
                    cnt++;
                }
            }
        }
        return dfs(grid,sr,sc,cnt);
    }
};
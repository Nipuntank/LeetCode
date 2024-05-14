class Solution {
public:
    int maxGold=0;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int dfs(int row,int col,vector<vector<int>>&grid,int m,int n)
    {
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==0)
        {
            return 0;
        }
        int curr=grid[row][col];
        grid[row][col]=0;
        int localMax=curr;
        for(int i=0;i<4;i++)
        {
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            localMax=max(localMax,curr+dfs(nrow,ncol,grid,m,n));
        }
        grid[row][col]=curr;
        return localMax;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    maxGold=max(maxGold,dfs(i,j,grid,m,n));
                }
            }
        }
        return maxGold;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
        {
            return -1;
        }
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>cost(m,vector<int>(n,1e9));
        cost[0][0]=0;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        int dx[8]={-1,-1,0,1,1,1,0,-1};
        int dy[8]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int step=q.front().second;
            q.pop();
            if(x==m-1 && y==n-1)
            {
                return step;
            }
            for(int i=0;i<8;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !grid[nx][ny] && step+1<cost[nx][ny])
                {
                    cost[nx][ny]=step+1;
                    q.push({{nx,ny},step+1});
                    if(nx==m-1 && ny==n-1)
                    {
                        return step+1;
                    }
                    
                }
            }
        }
        return -1;
    }
};
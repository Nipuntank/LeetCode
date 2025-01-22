class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j]==1)
                    q.push({i,j});
                else
                    ans[i][j]=-1;
            }
        }
        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && ans[nr][nc]==-1)
                {
                    ans[nr][nc]=ans[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return ans;
    }
};
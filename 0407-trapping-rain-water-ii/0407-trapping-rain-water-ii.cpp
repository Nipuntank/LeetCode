class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n;i++)
        {
            vis[0][i]=1;
            vis[m-1][i]=1;
            pq.push({heightMap[0][i],{0,i}});
            pq.push({heightMap[m-1][i],{m-1,i}});
        }
        for(int j=0;j<m;j++)
        {
            vis[j][0]=1;
            vis[j][n-1]=1;
            pq.push({heightMap[j][0],{j,0}});
            pq.push({heightMap[j][n-1],{j,n-1}});

        }
        int ans=0;
        while(!pq.empty())
        {
            int h=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc])
                {
                    ans+=max(0,h-heightMap[nr][nc]);
                    pq.push({max(h,heightMap[nr][nc]),{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int scolor=image[sr][sc];
        if(color==scolor)
        {
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            for(int i=0;i<4;i++)
            {
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==scolor)
                {
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};
class Solution {
public:
    int dx[8]={-1,-1,-1,0,1,1,1,0};
    int dy[8]={-1,0,1,1,1,0,-1,-1};
    void dfs(int row,int col,int &cnt,vector<vector<int>>&board,int m,int n)
    {
        for(int i=0;i<8;i++)
        {
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]==1)
            {
                cnt++;
            }
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        int cnt;
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cnt=0;
                dfs(i,j,cnt,board,m,n);
                if(board[i][j]==1)
                {
                    if(cnt<2)
                    {
                        ans[i][j]=0;
                    }
                    else if(cnt==2 || cnt==3)
                    {
                        ans[i][j]=1;
                    }
                    else if(cnt>3)
                    {
                        ans[i][j]=0;
                    }
                }
                else{
                    if(cnt==3 && board[i][j]==0)
                    {
                        ans[i][j]=1;
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]=ans[i][j];
            }
        }
    }
};
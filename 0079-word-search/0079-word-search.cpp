class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool dfs(int row,int col,int k,vector<vector<int>>&vis,vector<vector<char>>&board,string &word,int m,int n)
    {
        if(k==word.size())
        {
            return true;
        }
        if(row<0 || row>=m || col<0 || col>=n || vis[row][col] || word[k]!=board[row][col])
        {
            return false;
        }
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(dfs(nrow,ncol,k+1,vis,board,word,m,n))
            {
                return true;
            }
        }
        vis[row][col]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int k=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[k])
                {
                    if(dfs(i,j,k,vis,board,word,m,n))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
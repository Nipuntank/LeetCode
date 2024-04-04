class Solution {
public:
    bool dfs(vector<vector<char>>&board,string word,int row,int col,int index,int m,int n)
    {
        if(index==word.length())
        {
            return true;
        }
        if(row<0 || row>=m || col<0 || col>=n || board[row][col]!=word[index] || board[row][col]=='!')
        {
            return false;
        }
        char c =board[row][col];
        board[row][col]='!';
        bool top=dfs(board,word,row-1,col,index+1,m,n);
        bool bottom=dfs(board,word,row+1,col,index+1,m,n);
        bool left=dfs(board,word,row,col-1,index+1,m,n);
        bool right=dfs(board,word,row,col+1,index+1,m,n);
        board[row][col]=c;
        bool ans=top || bottom || left || right;
        return ans;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int index=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[index])
                {
                    if(dfs(board,word,i,j,index,m,n))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
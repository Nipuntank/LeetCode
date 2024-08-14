class Solution {
public:
    bool isEmpty(int &row,int &col,vector<vector<char>>&board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        return false;
    }
    bool isSafe(int row,int col,int val,vector<vector<char>>&board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==val)
            {
                return false;
            }
        }
        for(int j=0;j<9;j++)
        {
            if(board[row][j]==val)
            {
                return false;
            }
        }
        int rowF=row-(row%3);
        int colF=col-(col%3);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[rowF+i][colF+j]==val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isSudoko(vector<vector<char>>&board)
    {
        int row=0,col=0;
        if(!isEmpty(row,col,board))
        {
            return true;
        }
        for(char i='1';i<='9';i++)
        {
            if(isSafe(row,col,i,board))
            {
                board[row][col]=i;
                if(isSudoko(board))
                {
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        isSudoko(board);
    }
};
class Solution {
    vector<vector<string>>ans;
    vector<string>temp;
public:
    bool isPossible(int row,int col,int n,vector<vector<int>>&board)
    {
        for(int i=row-1;i>=0;i--)
        {
            if(board[i][col]==1)
            {
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--)
        {
            if(board[i][j]==1)
            {
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
        {
            if(board[i][j]==1)
            {
                return false;
            }
        }
        return true;
    }
    void solve(int row,int n,vector<vector<int>>&board)
    {
        if(row==n)
        {
            temp.clear();
            for(int i=0;i<n;i++)
            {
                string sol="";
                for(int j=0;j<n;j++)
                {
                    if(board[i][j]==1)
                    {
                        sol+="Q";
                    }
                    else{
                        sol+=".";
                    }
                }
                temp.push_back(sol);
            }
            ans.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            if(isPossible(row,i,n,board))
            {
                board[row][i]=1;
                solve(row+1,n,board);
                board[row][i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        solve(0,n,board);
        return ans;
    }
};
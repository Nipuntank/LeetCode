class Solution {
public:
    vector<vector<string>>ans;
    vector<string>temp;
    bool isPossible(int row,int col,vector<vector<int>>&board,int n)
    {
        
        for(int i=row-1;i>=0;i--)
        {
            if(board[i][col]==1)
            {
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
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
    void helper(vector<vector<int>>&board,int n,int row)
    {
        if(row==n)
        {
            temp.clear();
            for(int i=0;i<n;i++)
            {
                string st="";
                for(int j=0;j<n;j++)
                {
                    if(board[i][j]==1)
                    {
                        st+='Q';
                    }
                    else{
                        st+='.';
                    }
                }
                temp.push_back(st);
            }
            ans.push_back(temp);
            return ;
            
        }
        for(int j=0;j<n;j++)
        {
            if(isPossible(row,j,board,n))
            {
                board[row][j]=1;
                helper(board,n,row+1);
                board[row][j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        helper(board,n,0);
        return ans;
    }
};
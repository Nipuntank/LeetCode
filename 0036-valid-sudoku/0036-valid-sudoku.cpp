class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>row[9],col[9],box[9];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                char val=board[i][j];
                int boxIndex=(i/3)*3+(j/3);
                if(row[i].count(val) || col[j].count(val) || box[boxIndex].count(val))
                    return false;
                row[i].insert(val);
                col[j].insert(val);
                box[boxIndex].insert(val);
            }

        }
        return true;

    }
};
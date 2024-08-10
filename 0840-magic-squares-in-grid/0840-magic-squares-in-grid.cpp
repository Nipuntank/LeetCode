class Solution {
public:
    bool isMagic(int i,int j,vector<vector<int>>&grid)
    {
        vector<int>count(10,0);
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                int num=grid[i+x][j+y];
                if(num<1 || num>9 || count[num]>0)
                {
                    return false;
                }
                count[num]++;
            }
        }
        int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];
        for(int x=0;x<3;x++)
        {
            if(sum!=grid[i+x][j]+grid[i+x][j+1]+grid[i+x][j+2])
            {
                return false;
            }
        }
        for(int y=0;y<3;y++)
        {
            if(sum!=grid[i][j+y]+grid[i+1][j+y]+grid[i+2][j+y])
            {
                return false;
            }
        }
        if(sum!=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2] || sum!=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j])
        {
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(r<3 || c<3)
        {
            return 0;
        }
        int cnt=0;
        for(int i=0;i<=r-3;i++)
        {
            for(int j=0;j<=c-3;j++)
            {
                if(isMagic(i,j,grid))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    void flipCol(int col,vector<vector<int>>&temp,int m,int n)
    {
        for(int i=0;i<m;i++)
        {
           temp[i][col]=1-temp[i][col];
        }
    }
    void flipRow(int row,vector<vector<int>>&temp,int m,int n)
    {
        for(int j=0;j<n;j++)
        {
            temp[row][j]=1-temp[row][j];
        }
    }
    int conv(vector<vector<int>>&temp,int m,int n)
    {
        int ans=0;
        for(int i=m-1;i>=0;i--)
        {
            int p=0;
            for(int j=n-1;j>=0;j--)
            {
                ans+=temp[i][j]*pow(2,p);
                p++;
            }
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {
        vector<vector<int>>temp=grid;
        int m=temp.size();
        int n=temp[0].size();
        for(int i=0;i<m;i++)
        {
            if(temp[i][0]==0)
            {
                flipRow(i,temp,m,n);
            }
        }
        for(int j=0;j<n;j++)
        {
            int cnt=0;
            for(int i=0;i<m;i++)
            {
               if(temp[i][j]==0)
               {
                   cnt++;
               }
            }
            if(cnt>m/2)
            {
                flipCol(j,temp,m,n);
            }
        }
        int ans=conv(temp,m,n);
        return ans;
        
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>curr(n,0);
        vector<int>front(n,0);
        for(int i=n-1;i>=0;i--)
        {
            front[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int a=triangle[i][j]+front[j];
                int b=triangle[i][j]+front[j+1];
                curr[j]=min(a,b);
            }
            front=curr;
        }
        return front[0];
    }
};
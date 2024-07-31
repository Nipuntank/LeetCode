class Solution {
public:
    int dp[1001][1001];
    int b;
    int helper(int i,int remWidth,int layer,vector<vector<int>>&books)
    {
        if(i<0)
        {
            return layer;
        }
        if(dp[i][remWidth]!=-1)
        {
            return dp[i][remWidth];
        }
        int w=books[i][0];
        int h=books[i][1];
        int newLayer=layer+helper(i-1,b-w,h,books);
        int sameLayer=1e9;
        if(w<=remWidth)
        {
            sameLayer=helper(i-1,remWidth-w,max(h,layer),books);
        }
        return dp[i][remWidth]=min(newLayer,sameLayer);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
       memset(dp,-1,sizeof(dp));
        b=shelfWidth;
        int n=books.size();
        int a=shelfWidth;
        return helper(n-1,a,0,books);
    }
};
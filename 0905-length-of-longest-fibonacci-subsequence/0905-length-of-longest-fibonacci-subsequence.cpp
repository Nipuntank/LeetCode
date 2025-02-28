class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int len=0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=2;i<n;i++)
        {
            int a=0;
            int b=i-1;
            while(a<b)
            {
                if(arr[a]+arr[b]<arr[i])
                    a++;
                else if(arr[a]+arr[b]>arr[i])
                    b--;
                else{
                    dp[b][i]=1+dp[a][b];
                    len=max(len,dp[b][i]);
                    a++;
                    b--;
                }
            }
        }
        return len==0?0:len+2;
    }
};
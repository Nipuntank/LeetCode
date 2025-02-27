class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n =arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int len=0;
        for(int i=2;i<n;i++)
        {
            int s=0,e=i-1;
            while(s<e)
            {
                int sum=arr[s]+arr[e];
                if(sum>arr[i])
                    e--;
                else if(sum<arr[i])
                    s++;
                else{
                    dp[e][i]=dp[s][e]+1;
                    len=max(dp[e][i],len);
                    e--;
                    s++;
                }
            }
        }
        return len==0?0:len+2;
    }
};
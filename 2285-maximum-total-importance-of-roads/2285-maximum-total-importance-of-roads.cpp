class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        for(auto it:roads)
        {
            degree[it[0]]++;
            degree[it[1]]++;
        }
        vector<int>imp(n,0);
        for(int i=0;i<n;i++)
        {
            imp[i]=i;
        }
        sort(imp.begin(),imp.end(),[&](int a,int b){
            return degree[a]>degree[b];
        });
        long long t=0;
        for(int i=0;i<n;i++)
        {
            t+=(long long)(n-i)*degree[imp[i]];
        }
        return t;
    }
};
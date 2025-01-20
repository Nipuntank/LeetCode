class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)  {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,pair<int,int>>mp;
        vector<int>rows(m,n),cols(n,m);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            int val=arr[i];
            auto [r,c]=mp[val];
            if(--rows[r]==0|| --cols[c]==0)
                return i;
        }
        return -1;
    }
};
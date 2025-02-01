class Solution {
public:
    int max_element(int j,vector<vector<int>>&mat)
    {
        int idx=-1;
        int maxi=INT_MIN;
        for(int i=0;i<mat.size();i++)
        {
            if(maxi<mat[i][j])
            {
                maxi=mat[i][j];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int idx=max_element(mid,mat);
            int left=mid>0?mat[idx][mid-1]:-1;
            int right=mid<n-1?mat[idx][mid+1]:-1;
            if(mat[idx][mid]>left && mat[idx][mid]>right)
            {
                return{idx,mid};
            }
            else if(mat[idx][mid]<left)
            {
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return{};
    }
};
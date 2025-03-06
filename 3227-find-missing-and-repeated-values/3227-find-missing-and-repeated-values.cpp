class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int n_sq=n*n;
        long long sum=1LL*n_sq*(n_sq+1)/2;
        long long sum_sq=1LL * n_sq *(n_sq+1)*(2*n_sq+1)/6;
        long actual_sum=0,actual_sum_sq=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                actual_sum+=grid[i][j];
                actual_sum_sq+=(long long)grid[i][j]*grid[i][j];
            }
        }
        long long diff_sum=actual_sum-sum;
        long long diff_sum_sq=actual_sum_sq-sum_sq;
        long long sum_ab=diff_sum_sq/diff_sum;
        int a=(sum_ab+diff_sum)/2;
        int b=(sum_ab-diff_sum)/2;
        return {a,b};
    }
};
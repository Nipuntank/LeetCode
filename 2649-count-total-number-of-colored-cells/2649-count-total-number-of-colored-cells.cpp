class Solution {
public:
    long long coloredCells(int n) {
        if(n==0 || n==1)
            return n;
        long long a=(n-1)*4+coloredCells(n-1);
        return a;
    }
};
class Solution {
public:
    int Search(vector<int>&arr,int val)
    {
        int l=0,h=arr.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(arr[mid]==val)
                return 1;
            else if(arr[mid]<val)
                l=mid+1;
            else
                h=mid-1;
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            if(Search(matrix[i],target))
                return true;
        }
        return false;
    }
};
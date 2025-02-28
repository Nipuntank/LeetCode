class Solution {
public:
    int helper(vector<int>&arr,int a,int b,int n)
    {
        int idx=lower_bound(arr.begin(),arr.end(),a+b)-arr.begin();
        if(idx<n && arr[idx]==a+b)
        {
            return 1+helper(arr,b,a+b,n);
        }
        return 0;

    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int maxlen=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int a=arr[i];
                int b=arr[j];
                int len=helper(arr,a,b,n);
                if(len>0)
                    maxlen=max(maxlen,2+len);

            }
        }
        return maxlen;
    }
};
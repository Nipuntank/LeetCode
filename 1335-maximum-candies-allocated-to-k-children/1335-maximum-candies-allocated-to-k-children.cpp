class Solution {
public:
    bool helper(long long mid,vector<int>&candies,long long k)
    {
        long long cnt=0;
        for(auto it:candies)
        {
            if(it>=mid)
                cnt+=it/mid;
        }
        return cnt>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long  l=1,r=*max_element(candies.begin(),candies.end());
        long long mid;
        long long ans=0;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(helper(mid,candies,k))
            {
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
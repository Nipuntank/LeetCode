class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        long long oddCnt=0,prefixSum=0;
        for(auto it:arr)
        {
            prefixSum+=it;
            oddCnt+=prefixSum%2;
        }
        oddCnt+=(arr.size()-oddCnt)*oddCnt;
        return oddCnt%mod;
    }
};
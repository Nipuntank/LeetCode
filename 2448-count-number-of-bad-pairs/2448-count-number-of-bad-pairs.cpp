class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        long long cnt=0;
        long long n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            int p=nums[i]-i;
            cnt+=mp[p];
            mp[p]++;
        }
        return (n*(n-1))/2-cnt;
    }
};
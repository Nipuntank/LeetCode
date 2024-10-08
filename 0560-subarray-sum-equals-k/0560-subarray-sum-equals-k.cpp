class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int cnt=0;
        mp[sum]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int left=sum-k;
            if(mp.find(left)!=mp.end())
            {
                cnt+=mp[left];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
class Solution {
public:
    int helper(int num)
    {
        if(num>=0 && num<=9)
            return num;
        int sum=0;
        while(num)
        {
            sum+=(num%10);
            num=num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<long long>>mp;
        for(int i=0;i<n;i++)
        {
            int e=helper(nums[i]);
            mp[e].push_back(nums[i]);
        }
        long long ans=-1;
        for(auto it:mp)
        {
            if(it.second.size()>=2)
            {
                sort(it.second.begin(),it.second.end(),greater<int>());
                ans=max(ans,it.second[0]+it.second[1]);
            }
        }
        return ans;
    }
};
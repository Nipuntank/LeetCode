class Solution {
public:
    set<vector<int>>s;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int a=-(nums[i]+nums[j]);
                if(mp.count(a) && mp.find(a)->second>j)
                {
                    s.insert({nums[i],nums[j],a});
                }
            }
        }
        return vector<vector<int>>(s.begin(),s.end());
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=0;
        int ele=0;
        for(auto it:nums)
        {
            mp[it]++;
            if(maxi<mp[it])
            {
                maxi=mp[it];
                ele=it;
            }
        }
        return ele;
    }
};
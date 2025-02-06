class Solution {
public:
    int nC2(int n)
    {
        return (n*(n-1))/2;
    }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto it:mp)
        {
            ans+=8*nC2(it.second);
        }
        return ans;
    }
};
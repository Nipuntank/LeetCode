class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return true;
        int i=0;
        while(i<n-1 && nums[i]<=nums[i+1])
            i++;
        if(i==n-1)
            return true;
        i++;
        while(i<n-1 && nums[i]<=nums[i+1] && nums[i]<=nums[0])
            i++;
        if(i==n-1 && nums[i]<=nums[0])
            return true;
        return false;
        
    }
};
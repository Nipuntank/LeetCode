class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return true;
        for(int i=1;i<n;i++)
        {
            int prev=nums[i-1];
            int curr=nums[i];
            if((prev%2==0 && curr%2==0) || (prev%2==1 && curr%2==1))
                return false;
        }
        return true;
    }
};
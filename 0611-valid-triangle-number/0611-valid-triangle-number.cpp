class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            int l=0,h=i-1;
            while(l<h)
            {
                int sum=nums[l]+nums[h];
                if(sum>nums[i])
                {
                    cnt+=h-l;
                    h--;
                }
                else    
                    l++;
            }
        }
        return cnt;
    }
};
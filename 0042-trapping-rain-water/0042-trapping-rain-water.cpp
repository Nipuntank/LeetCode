class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int lh=-1e9;
        int rh=-1e9;
        int left=0;
        int right=height.size()-1;
        while(left<right)
        {
            lh=max(height[left],lh);
            rh=max(height[right],rh);
            if(lh<rh)
            {
                ans+=lh-height[left];
                left++;
            }
            else{
                ans+=rh-height[right];
                right--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int k=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int a=prices[i]-k;
            k=min(k,prices[i]);
            maxi=max(maxi,a);
        }
        return maxi;
    }
};
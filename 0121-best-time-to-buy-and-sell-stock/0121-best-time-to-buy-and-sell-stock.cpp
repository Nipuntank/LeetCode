class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int p=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int c=prices[i]-p;
            p=min(p,prices[i]);
            maxi=max(maxi,c);
        }
        return maxi;
    }
};
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0;
        int i=0;
        while(k--)
        {
            happiness[i]=max(happiness[i]-i,0);
            ans+=happiness[i++];
        }
        return ans;
    }
};
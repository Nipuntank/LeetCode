
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double d=(double)arr[j]/(double)arr[i];
                pq.push({d,{arr[i],arr[j]}});
            }
        }
        int count=0;
        while(--k)
        {
            pq.pop();
        }
        auto it=pq.top();
        return {it.second.first,it.second.second};
    }
};
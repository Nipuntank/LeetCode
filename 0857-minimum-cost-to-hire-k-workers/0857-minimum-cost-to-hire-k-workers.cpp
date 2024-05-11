class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        double qualityTillNow=0;
        double minCost=DBL_MAX;
        vector<pair<double,int>>getRatio;
        for(int i=0;i<n;i++)
        {
            getRatio.push_back({(wage[i]*1.0)/quality[i],quality[i]});
        }
        sort(getRatio.begin(),getRatio.end());
        priority_queue<int>pq;
        for(auto it:getRatio)
        {
            double currRatio=it.first;
            int q=it.second;
            
            qualityTillNow+=q;
            pq.push(q);
            
            while(pq.size()>k)
            {
                qualityTillNow-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                minCost=min(minCost,qualityTillNow*currRatio);
            }
            
        }
        return minCost;
    }
};
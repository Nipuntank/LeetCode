class Solution {
public:
    bool findPath(int i,int parent,vector<int>adj[],vector<int>&curr_path,vector<int>&bob_path)
    {
        if(i==0)
        {
            curr_path.push_back(i);
            bob_path =curr_path;
            return true;
        }
        curr_path.push_back(i);
        for(auto it:adj[i])
        {
            if(it!=parent && findPath(it,i,adj,curr_path,bob_path))
                return true;            
            
        }
        curr_path.pop_back();
        return false;
    }
    int findMaxPath(vector<int>adj[],int i,int parent,vector<int>&amount)
    {
        int maxIncome=INT_MIN;
        for(auto it:adj[i])
        {
            if(it!=parent)
            {
                int income=findMaxPath(adj,it,i,amount);
                if(maxIncome<income+amount[i])
                    maxIncome=income+amount[i];
            }
        }
        return maxIncome==INT_MIN?amount[i]:maxIncome;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>curr_path;
        vector<int>bob_path;
        findPath(bob,-1,adj,curr_path,bob_path);
        int len=bob_path.size();
        int i;
        for(i=0;i<len/2;i++)
            amount[bob_path[i]]=0;
        if(len%2==1)
            amount[bob_path[len/2]]/=2;
        return findMaxPath(adj,0,-1,amount);

    }
};
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>>ans(n,vector<int>(2,-1));
        sort(people.begin(),people.end(),cmp);
        for(int i=0;i<n;i++)
        {
            int cnt=people[i][1];
            for(int j=0;j<n;j++)
            {
                if(ans[j][0]==-1 && cnt==0)
                {
                    ans[j][0]=people[i][0];
                    ans[j][1]=people[i][1];
                    break;
                }
                else if(ans[j][0]==-1 || ans[j][0]>=people[i][0])
                    cnt--;
            }
        }
        return ans;
    }
};
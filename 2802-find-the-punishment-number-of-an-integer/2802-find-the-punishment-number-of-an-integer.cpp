class Solution {
public:
    int solve(string num,int target,int idx,int currSum)
    {
        if(currSum>target)
            return 0;
        if(idx==num.size())
            return currSum==target;
        for(int i=idx+1;i<=num.size();i++)
        {
            string str=num.substr(idx,i-idx);
            int part=stoi(str);
            if(solve(num,target,i,currSum+part))
                return 1;
        }
        return 0;

    }
    int solve(string num,int target)
    {
        return solve(num,target,0,0);
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int sq=i*i;
            if(solve(to_string(sq),i))
                ans+=sq;
        }
        return ans;
    }
};
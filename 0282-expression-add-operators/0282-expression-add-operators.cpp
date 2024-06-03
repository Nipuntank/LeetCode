class Solution {
public:
    vector<string>ans;
    void helper(string num,int target,int i,long total,const string &exp,long prev )
    {
        int n=num.size();
        if(i==n)
        {
            if(total==target)
            {
                ans.push_back(exp);
                return ;
            }
            
        }
        long currNum=0;
        string currStr;
            
        for(int j=i;j<n;j++)
        {
            if(j>i && num[i]=='0')
            {
                return;
            }
            currNum=currNum *10+(num[j]-'0');
            currStr += num[j];
            if(i==0)
            {
                helper(num,target,j+1,currNum,exp+currStr,currNum);
            }
            else{
                helper(num,target,j+1,total+currNum,exp+"+"+currStr,currNum);
                helper(num,target,j+1,total-currNum,exp+"-"+currStr,-currNum);
                helper(num,target,j+1,total-prev+currNum*prev,exp+"*"+currStr,currNum*prev);
            }
        }
        
    }
    vector<string> addOperators(string num, int target) {
        
        helper(num,target,0,0,"",0);
        return ans;
    }
};
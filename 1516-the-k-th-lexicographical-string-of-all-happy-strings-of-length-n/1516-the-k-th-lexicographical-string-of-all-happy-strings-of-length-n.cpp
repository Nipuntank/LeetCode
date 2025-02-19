class Solution {
public:
    string ans;
    void helper(vector<char>&arr,string temp,int len,int &k,int n)
    {
        if(len==n)
        {
            if(--k==0)
                ans=temp;
            return ;
        }
        for(int i=0;i<3;i++)
        {
            if(len==0 || temp.back()!=arr[i])
            {
                temp.push_back(arr[i]);
                helper(arr,temp,len+1,k,n);
                temp.pop_back();
               
                
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<char>arr={'a','b','c'};
        ans="";
        helper(arr,"",0,k,n);
        return ans;
    }
};
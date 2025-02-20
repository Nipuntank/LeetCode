class Solution {
public:
    set<string>s;
    string ans;
    int find=0;
    void helper(string &temp,int idx,int n)
    {
        if(idx==n)
        {
            if(s.find(temp)==s.end())
            {
                ans= temp;
                find=1;
                return ;
            }
                
            return ;
        }
        if(find)
            return ;
        temp[idx]='0';
        helper(temp,idx+1,n);
        if(find)
            return ;
        temp[idx]='1';
        helper(temp,idx+1,n);

    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        if(n==0)
            return "";
        ans="";
        s.insert(nums.begin(),nums.end());
        string temp(n,'0');
        helper(temp,0,n);
        return ans;
    }
};
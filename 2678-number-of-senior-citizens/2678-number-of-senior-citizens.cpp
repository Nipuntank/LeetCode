class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto it:details)
        {
            string ans="";
            ans+=it[11];
            ans+=it[12];
            int age=stoi(ans);
            if(age>60)
            {
                count++;
            }
        }
        return count;
    }
};
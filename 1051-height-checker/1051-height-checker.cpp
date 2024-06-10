class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>count(101,0);
        for(auto it:heights)
        {
            count[it]++;
        }
        int i=1,j=0;
        int cnt=0;
        while(i<101)
        {
            if(count[i]==0)
            {
                i++;
            }
            else{
                if(i!=heights[j])
                {
                    cnt++;
                }
                j++;
                count[i]--;
            }
        }
        return cnt;
        
    }
};
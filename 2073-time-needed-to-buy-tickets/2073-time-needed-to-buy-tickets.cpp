class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int cnt=0;
        int index=0;
        while(tickets[k]!=0)
        {
            if(tickets[index]>0)
            {
                cnt++;
                tickets[index]--;
                index=(index+1)%n;
            }
            else if(tickets[index]==0)
            {
                index=(index+1)%n;
            }
        }
        return cnt;
    }
};
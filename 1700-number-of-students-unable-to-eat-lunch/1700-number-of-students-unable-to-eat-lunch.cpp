class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        vector<int>count(2,0);
        for(auto it:students)
        {
            count[it]++;
        }
        int remaining=sandwiches.size();
        for(auto it:sandwiches)
        {
            if(remaining==0)
            {
                break; 
            }
            if(count[it]==0)
            {
                break;
            }
            count[it]--;
            remaining--;
        }
        return remaining;
    }
};
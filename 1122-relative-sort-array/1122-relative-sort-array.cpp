class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>count(1001,0);
        vector<int>ans;
        for(auto it:arr1)
        {
            count[it]++;
        }
        for(auto it:arr2)
        {
            while(count[it]--)
            {
                ans.push_back(it);
            }
        }
        for(int i=0;i<count.size();i++)
        {
            while(count[i]-- >0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
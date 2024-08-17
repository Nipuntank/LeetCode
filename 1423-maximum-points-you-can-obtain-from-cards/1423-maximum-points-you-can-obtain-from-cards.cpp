class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score=0;
        for(int i=0;i<k;i++)
        {
            score+=cardPoints[i];
        }
        int maxi=score;
        for(int i=k-1;i>=0 ;i--)
        {
            score-=cardPoints[i];
            score+=cardPoints[cardPoints.size()-k+i];
            maxi=max(maxi,score);
        }
        return maxi;
    }
};
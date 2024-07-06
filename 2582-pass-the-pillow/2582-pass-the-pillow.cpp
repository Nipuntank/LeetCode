class Solution {
public:
    int passThePillow(int n, int time) {
        int a=2*n-2;
        int b=time%a;
        if(b<n)
        {
            return b+1;
        }
        else{
            return a-b+1;
        }
    }
};
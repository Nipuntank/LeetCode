class Solution {
public:
    bool isPrime(long long N)
    {
        if(N<=3)
            return N>1;
        if(!(N%6==1 || N%6==5))
            return 0;
        for(long long i=5;i*i<=N;i+=6)
        {
            if(N%i==0 || N%(i+2)==0)
                return 0;
        }
        return 1;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans={-1,-1};
        int range=INT_MAX,prev=-1;
        for(int i=left;i<=right;i++)
        {
            if(isPrime(i))
            {
                if(prev!=-1 && i-prev<range)
                {
                    ans={prev,i};
                    range=i-prev;
                }
                prev=i;
            }
        }
        return ans;
    }
};
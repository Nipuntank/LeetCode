class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        int i=0;
        long ans=0;
        while(i<s.length() && s[i]==' ')
        {
           i++; 
        }
        if(s[i]=='+')
        {
            i++;
        }
        else if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        while(i<s.length())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans=ans*10+(s[i]-'0');
                if(ans>INT_MAX && sign==-1)
                {
                    return INT_MIN;
                }
                else if(ans>INT_MAX && sign==1)
                {
                    return INT_MAX;
                }
                i++;
            }
            else{
                return ans*sign;
            }
        }
        return ans*sign;
    }
};
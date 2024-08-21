enum STATE{
    INIT,S1,S2,S3,I1,I2,I3,I4,I5
};
class Solution {
public:
    bool isNums(char c)
    {
        return c>=48 && c<=57;
    }
    bool isSafe(STATE a)
    {
        return a==S1 || a==S2 || a==S3;
    }
    bool isNumber(string s) {
        STATE curr=INIT;
        for(int i=0;i<s.size();i++)
        {
            if(curr==INIT && (s[i]=='+' || s[i]=='-'))
            {
                curr=I1;
            }
            else if(curr==INIT && isNums(s[i]))
            {
                curr=S1;
            }
            else if(curr==INIT && s[i]=='.')
            {
                curr=I2;
            }
            else if(curr==S1 && isNums(s[i]))
            {
                curr=S1;
            }
            else if(curr==I1 && isNums(s[i]))
            {
                curr=S1;
            }
            else if(curr==I1 && s[i]=='.')
            {
                curr=I2;
            }
            else if(curr==S1 && (s[i]=='E' || s[i]=='e'))
            {
                curr=I3;
            }
            else if(curr==S1 && s[i]=='.')
            {
                curr=S2;
            }
            else if(curr==I2 && isNums(s[i]))
            {
                curr=S2;
            }
            else if(curr==S2 && (s[i]=='e' || s[i]=='E'))
            {
                curr=I4;
            }
            else if(curr==S2 && isNums(s[i]))
            {
                curr=S2;
            }
            else if(curr==I3 && (s[i]=='+' || s[i]=='-'))
            {
                curr=I5;
            }
            else if(curr==I3 && isNums(s[i]))
            {
                curr=S3;
            }
            else if(curr==I4 && (s[i]=='+' || s[i]=='-'))
            {
                curr=I5;
            }
            else if(curr==I4 && isNums(s[i]))
            {
                curr=S3;
            }
            else if(curr==I5 && isNums(s[i]))
            {
                curr=S3;
            }
            else if(curr==S3 && isNums(s[i]))
            {
                curr=S3;
            }
            else{
                return false;
            }
        }
        return isSafe(curr);
    }
};
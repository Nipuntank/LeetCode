class Solution {
public:
    vector<int>val={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string>roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string ans;
        int i=0;
        while(num>0)
        {
            if(val[i]<=num)
            {
                ans+=roman[i];
                num-=val[i];
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
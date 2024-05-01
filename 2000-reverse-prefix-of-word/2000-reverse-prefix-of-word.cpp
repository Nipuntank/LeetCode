class Solution {
public:
    string reversePrefix(string word, char ch) {
        string temp=word;
        string s="";
        int i;
        for(i=0;i<word.size();i++)
        {
            s.push_back(temp[i]);
            if(word[i]==ch)
            {
                reverse(s.begin(),s.end());
                i++;
                break;
            }
            
            
            
        }
        
        while(i<word.size())
        {
            s.push_back(word[i++]);
        }
        return s;
    }
};
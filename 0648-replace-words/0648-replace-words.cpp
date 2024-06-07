class TrieNode{
    public:
    TrieNode *children[26];
    bool isTerminal;
    TrieNode()
    {
        isTerminal=false;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};
class Solution {
    TrieNode *root;
public:
    Solution(){
        root=new TrieNode();
    }
    void insertWord(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return ;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
        {
            root->children[index]=new TrieNode();
        }
        return insertWord(root->children[index],word.substr(1));
    }
    void insertWord(string word)
    {
        insertWord(root,word);
    }
    string search(string word)
    {
        TrieNode *node=root;
        string temp="";
        for(auto it:word)
        {
            int index=it-'a';
            if(node->children[index]==NULL)
            {
                return word;
            }
            temp+=it;
            if(node->children[index]->isTerminal)
            {
                return temp;
            }
            node=node->children[index];
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto it:dictionary)
        {
            insertWord(it);
        }
        string result="";
        string word="";
        for(auto ch:sentence)
        {
            if(ch==' ')
            {
                result+=search(word)+" ";
                word="";
            }
            else{
                word+=ch;
            }
        }
        result+=search(word);
        return result;
    }
};
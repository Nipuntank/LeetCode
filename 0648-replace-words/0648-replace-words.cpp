class TrieNode{
    public:
    bool isTerminal;
    char data;
    TrieNode **children;
    TrieNode(char data)
    {
        this->data=data;
        isTerminal=false;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};
class Solution {
    TrieNode *root;
public:
    Solution()
    {
        root=new TrieNode('\0');
    }
    void insert(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return ;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]==NULL)
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        else{
            child=root->children[index];
        }
        insert(child,word.substr(1));
    }
    void insert(string word){
        insert(root,word);
    }
    string search(string word)
    {
        TrieNode *node=root;
        string ans="";
        for(auto it:word)
        {
            int index=it-'a';
            if(node->children[index]==NULL)
            {
                return word;
            }
            ans+=it;
            if(node->children[index]->isTerminal)
            {
                return ans;
            }
            node=node->children[index];
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto it:dictionary)
        {
            insert(it);
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
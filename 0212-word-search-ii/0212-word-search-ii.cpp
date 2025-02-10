class TrieNode{
    public:
    TrieNode *child[26]={NULL};
    bool isWord=false;
};
class Solution {
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
public:
    void addWord(TrieNode *curr,string word)
    {
        for(auto ch:word)
        {
            if(!curr->child[ch-'a'])
                curr->child[ch-'a']=new TrieNode();
            curr=curr->child[ch-'a'];
        }
        curr->isWord=true;
    }
    void dfs(vector<string>&ans,string str,TrieNode *curr,int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis)
    {
        int m=board.size();
        int n=board[0].size();
        if(curr->isWord)
        {
            ans.push_back(str);
            curr->isWord=false;
        }
        vis[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && curr->child[board[ni][nj]-'a'])
                dfs(ans,str+board[ni][nj],curr->child[board[ni][nj]-'a'],ni,nj,board,vis);
        }
        vis[i][j]=false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *trie=new TrieNode();
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(auto it:words)
        {
            addWord(trie,it);
        }
        vector<string>ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch=board[i][j];
                if(trie->child[ch-'a'])
                    dfs(ans,string(1,ch),trie->child[ch-'a'],i,j,board,vis);
            }
        }
        return ans;
    }
};
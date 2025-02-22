/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i=0;
    TreeNode *helper(string str,int depth)
    {
        if(i>=str.size())
            return NULL;
        int d=0;
        while(str[i]=='-')
        {
            d++;
            i++;
        }
        if(d<depth)
        {
            i-=d;
            return NULL;
        }
        int x=0;
        while(isdigit(str[i]))
        {
            x=x*10+str[i]-'0';
            i++;
        }
        TreeNode *node=new TreeNode(x);
        node->left=helper(str,depth+1);
        node->right=helper(str,depth+1);
        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        return helper(traversal,0);
    }
};
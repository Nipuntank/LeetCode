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
    void helper(TreeNode *root,int val,int depth,int h)
    {
        if(root==NULL)
        {
            return ;
        }
        if(h==depth-1)
        {
            TreeNode *leftNode=new TreeNode(val);
            leftNode->left=root->left;
            root->left=leftNode;
            TreeNode *rightNode=new TreeNode(val);
            rightNode->right=root->right;
            root->right=rightNode;  
            return ;
        }
        helper(root->left,val,depth,h+1);
        helper(root->right,val,depth,h+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode *node=new TreeNode(val);
            node->left=root;
            node->right=NULL;
            return node;
            
        }
        helper(root,val,depth,1);
        return root;
    }
};
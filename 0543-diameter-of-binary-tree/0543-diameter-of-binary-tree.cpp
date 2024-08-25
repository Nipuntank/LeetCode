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
    int findHeight(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int a=1+findHeight(root->left);
        int b=1+findHeight(root->right);
        return max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int a=diameterOfBinaryTree(root->left);
        int b=diameterOfBinaryTree(root->right);
        int c=findHeight(root->left)+findHeight(root->right);
        return max(a,max(b,c));
    }
};
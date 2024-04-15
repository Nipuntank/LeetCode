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
    void helper(TreeNode *root,int currSum,int &sum)
    {
        if(root==NULL)
        {
            return ;
        }
        currSum=currSum*10+root->val;
        if(!root->left && !root->right)
        {
            sum+=currSum;
            return ;
        }
        helper(root->left,currSum,sum);
        helper(root->right,currSum,sum);
        return ;
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        helper(root,0,sum);
        return sum;
    }
};
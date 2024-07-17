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
    vector<TreeNode *>ans;
    unordered_set<int>mp;
    void helper(TreeNode* &root)
    {
        if(root)
        {
            helper(root->left);
            helper(root->right);
            if(mp.find(root->val)!=mp.end())
            {
                if(root->left){
                    ans.push_back(root->left);
                }
                if(root->right){
                    ans.push_back(root->right);
                }
                root=NULL;
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto it:to_delete)
        {
            mp.insert(it);
        }
        helper(root);
        if(root)
        {
            ans.push_back(root);
        }
        return ans;
    }
};
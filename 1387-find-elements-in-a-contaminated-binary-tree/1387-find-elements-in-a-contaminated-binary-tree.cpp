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
class FindElements {
    TreeNode *node;
public:
    void helper(TreeNode *root)
    {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto[node,idx]=q.front();
            q.pop();
            node->val=idx;
            if(node->left)
            {
                q.push({node->left,idx*2+1});
            }
            if(node->right)
            {
                q.push({node->right,idx*2+2});
            }
        }
    }
    FindElements(TreeNode* root) {
        node=root;
        helper(node);
    }
    bool find(TreeNode *root,int val)
    {
        if(!root)
            return false;
        if(root->val==val)
            return true;
        return find(root->left,val) || find(root->right,val);
        
    }
    bool find(int target) {
        return find(node,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
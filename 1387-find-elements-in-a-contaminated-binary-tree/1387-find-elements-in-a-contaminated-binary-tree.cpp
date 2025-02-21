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
    unordered_map<int,int>mp;
public:
    FindElements(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto[node,idx]=q.front();
            q.pop();
            node->val=idx;
            mp[idx]++;
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
    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
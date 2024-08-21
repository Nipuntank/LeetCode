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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        stack<TreeNode *>odd;
        stack<TreeNode *>even;
        odd.push(root);
        vector<int>temp;
        while(!odd.empty() || !even.empty())
        {
            temp.clear();
            if(!even.empty())
            {
                while(!even.empty())
                {
                    TreeNode *node=even.top();
                    even.pop();
                    temp.push_back(node->val);
                    if(node->right)
                    {
                        odd.push(node->right);
                    }
                    if(node->left)
                    {
                        odd.push(node->left);
                    }
                }
                
            }
            else{
                while(!odd.empty())
                {
                    TreeNode *node=odd.top();
                    odd.pop();
                    temp.push_back(node->val);
                    if(node->left)
                    {
                        even.push(node->left);
                    }
                    if(node->right)
                    {
                        even.push(node->right);
                    }
                }
                
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
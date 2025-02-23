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
    TreeNode *helper(vector<int>&preorder,int preS,int preE,vector<int>&postorder,int poS,int poE)
    {
        if(preS>preE || poS>poE)
            return NULL;
        TreeNode *root=new TreeNode(preorder[preS]);
        if(preS==preE)
            return root;
        int i=poS;
        while(i<=poE)
        {
            if(postorder[i]==preorder[preS+1])
                break;
            i++;
        }
        int left=i-poS;
        root->left=helper(preorder,preS+1,preS+left+1,postorder,poS,i);
        root->right=helper(preorder,preS+left+2,preE,postorder,i+1,poE);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return helper(preorder,0,n-1,postorder,0,n-1);
        
    }
};
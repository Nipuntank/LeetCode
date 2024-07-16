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
    void rootToNode(TreeNode *root,int startValue,int destValue,string &a,string &b,string &temp )
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->val==startValue)
        {
            a=temp;
        }
        if(root->val==destValue)
        {
            b=temp;
        }
        temp.push_back('L');
        rootToNode(root->left,startValue,destValue,a,b,temp);
        temp.pop_back();
        
        temp.push_back('R');
        rootToNode(root->right,startValue,destValue,a,b,temp);
        temp.pop_back();
        
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string a,b,temp;
        rootToNode(root,startValue,destValue,a,b,temp);
        
        string ans;
        int ind=0;
        for(int i=0;i<a.size() && i<b.size();i++)
        {
            if(a[i]==b[i])
            {
                ind=i+1;
            }
            else 
                break;
        }
        
        for(int i=ind;i<a.size();i++)
        {
            ans.push_back('U');
        }
        for(int i=ind;i<b.size();i++)
        {
            ans.push_back(b[i]);
        }
        return ans;
        
        
    }
};
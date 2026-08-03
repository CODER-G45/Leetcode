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
    bool helper(TreeNode* root,int val)
    {
        if(!root)return true;
        if(root->val != val)return false;
        if(!helper(root->left ,val)) return false;
        if(!helper(root->right,val)) return false;
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        return helper(root,root->val);
    }
};
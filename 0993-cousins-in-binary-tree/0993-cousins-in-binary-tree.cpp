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
private:
    int xd,yd;
    TreeNode* xp;
    TreeNode* yp;
    void depthF(TreeNode* root ,TreeNode* p, int x , int y ,int depth)
    {
        if(!root) return;
        if(root->val == x)xd = depth,xp = p;
        if(root->val == y)yd = depth,yp = p;
        depthF(root->left,root,x,y,depth+1);
        depthF(root->right,root,x,y,depth+1);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        depthF(root,NULL,x,y,0);
        return xd == yd && xp != yp;
    }
};
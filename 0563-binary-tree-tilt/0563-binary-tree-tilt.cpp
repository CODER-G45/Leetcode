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
    int tilt = 0;
    int sum(TreeNode* root)
    {
        if(!root) return 0;
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        tilt += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        sum(root);
        return tilt;
    }
};
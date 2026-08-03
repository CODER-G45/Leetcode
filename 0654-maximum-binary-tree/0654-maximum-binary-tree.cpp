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
    TreeNode* helper(vector<int>& nums ,int l , int r)
    {
        if(l > r) return NULL;
        int p = -1,maxel = INT_MIN;
        for(int i = l; i <= r; i++)
        {
            if(nums[i]>maxel)p=i,maxel=nums[i];
        }
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(nums,l,p-1);
        root->right = helper(nums,p+1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return  helper(nums,0,nums.size()-1);
    }
};
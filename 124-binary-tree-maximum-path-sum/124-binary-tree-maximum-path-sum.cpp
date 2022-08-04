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
    // this function gives maximum path compared to maxi from the node to null value
    int helper(TreeNode* root, int& maxi){
        if(!root) return 0;
        int lmax = max(0, helper(root->right, maxi));
        int rmax = max(0, helper(root->left, maxi));
        
        maxi = max(maxi, root->val + lmax + rmax);
        
        return max(lmax,rmax) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};
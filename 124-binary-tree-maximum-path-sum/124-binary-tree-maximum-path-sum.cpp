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
    // this function gives maximum path sum compared to maxi from the node to null value
    int helper(TreeNode* root, int& maxi){
        if(!root) return 0;
        
        // maximum path sum of left subtree from node
        int lmax = max(0, helper(root->left, maxi));
        // maximum path sum of right subtree from node
        int rmax = max(0, helper(root->right, maxi));
        
        // maximum of maxi or tree containing curr node as turning point
        maxi = max(maxi, root->val + lmax + rmax);
        
        // return maximum of (right subtree containing root->val, left subtree containing root->val)
        return max(lmax,rmax) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};
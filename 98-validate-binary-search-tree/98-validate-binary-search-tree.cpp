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
    bool validate(TreeNode* root, double minimum, double maximum){
        if(!root) return true;
        
        if(root->val > maximum || root->val < minimum) return false;
        
        return validate(root->left, minimum, double(root->val)-1) && validate(root->right, double(root->val)+1, maximum);
    }
    bool isValidBST(TreeNode* root) {
        double minimum = -DBL_MAX;
        double maximum = DBL_MAX;
        return validate(root,minimum, maximum);
    }
};
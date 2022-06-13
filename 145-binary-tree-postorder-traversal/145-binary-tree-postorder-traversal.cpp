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
    void getPostOrderTraversalHelper(TreeNode* root, vector<int>&res){
    if(!root) return;
    
    getPostOrderTraversalHelper(root->left,res);
    getPostOrderTraversalHelper(root->right,res);
    res.push_back(root->val);
    
}
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int>res;
    getPostOrderTraversalHelper(root,res);
    return res;
    }
};
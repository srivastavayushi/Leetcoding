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
    void traverse(TreeNode* root, int currentMax, int &res){
        if(!root){
            return;
        }
        
        if(currentMax <= root->val){
           currentMax = root->val;
            res += 1;
        }
        traverse(root->left,currentMax,res);
        traverse(root->right,currentMax,res);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root->left && !root->right){
            return 1;
        }
        int res = 0;
        traverse(root,root->val,res);
        return res;
    }
};
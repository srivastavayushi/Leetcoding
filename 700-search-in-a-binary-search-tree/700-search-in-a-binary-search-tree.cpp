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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        
        if(root->val==val){
            return root;
        }
        
        TreeNode* lroot = searchBST(root->left,val);
        TreeNode* rroot = searchBST(root->right,val);
        
        TreeNode* res = NULL;
        
        if(lroot != NULL && lroot->val==val){
            res=lroot;
        }else if(rroot != NULL && rroot->val==val){
            res=rroot;
        }
        
        return res;
    }
};
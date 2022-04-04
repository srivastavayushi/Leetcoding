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
    void giveSmallest(TreeNode* root, vector<int>&res){
        
        if (!root) {
            return;
        }
        
        giveSmallest(root->left, res);
        res.push_back(root->val);
        giveSmallest(root->right,res);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        
        giveSmallest(root, res);
        
        //cout<<res[k-1]<<endl;
        
        return res[k-1];
    }
};
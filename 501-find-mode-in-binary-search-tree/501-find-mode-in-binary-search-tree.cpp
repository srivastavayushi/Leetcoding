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
    unordered_map<int,int>mpp;
public:
    void traverse(TreeNode* root){
        if(!root) return;
        
        traverse(root->left);
        mpp[root->val]++;
        traverse(root->right);
        return;
        
    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        vector<int>res;
        int maximum = INT_MIN;
        
        for(auto it:mpp){
            maximum = max(it.second, maximum);
        }

        for(auto it:mpp){
            if(it.second == maximum) res.push_back(it.first);
        }

        return res;
    }
};
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
    void helper(TreeNode* root, string &curr_small, string curr_string){
        
        if(!root->left && !root->right){
            char temp = 'a' + root->val;
            curr_string.push_back(temp);
            reverse(curr_string.begin(),curr_string.end());
            // cout<<curr_string<<endl;
            curr_small = min(curr_small,curr_string);
            return;
        }
        
        char temp = 'a' + root->val;
        curr_string.push_back(temp);
        
        if(root->left) helper(root->left,curr_small,curr_string);
        if(root->right) helper(root->right,curr_small,curr_string);
        
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr_small(8500,'z');
        string curr_string = "";
        if(!root) return " ";
        helper(root,curr_small,curr_string);
        return curr_small;
        
    }
};
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
    TreeNode* createTree(vector<int>&nums, int l, int r){
        if(l>r) return NULL;
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createTree(nums,l,mid-1);
        root->right = createTree(nums,mid+1,r);
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return createTree(nums,0,nums.size()-1);
    }
};
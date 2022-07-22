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
class FindElements {
public:
    TreeNode* node;
    unordered_map<int,int>mpp;
    void clean(TreeNode* root, int value){
        if(!root) return;
        root->val = value;
        mpp[root->val]++;
        if(root->left) clean(root->left, 2*root->val+1);
        if(root->right) clean(root->right, 2*root->val+2);
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        mpp[0]++;
        if(root->left) clean(root->left, 2*root->val+1);
        if(root->right) clean(root->right, 2*root->val+2);
        node = root;
    }
    
    bool find(int target) {
        return mpp[target] ? true : false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
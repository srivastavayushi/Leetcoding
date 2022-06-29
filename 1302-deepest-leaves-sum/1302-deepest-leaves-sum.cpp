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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        vector<vector<int>> levelOrder;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            TreeNode* temp;
            
            for(int i=0;i<size;i++){
                temp = q.front();
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
            levelOrder.push_back(level);
        }
        
        int sum = 0;
        vector<int> leafNodes = levelOrder.back();
        for(auto it : leafNodes) sum+=it;
        
        return sum;
    }
};
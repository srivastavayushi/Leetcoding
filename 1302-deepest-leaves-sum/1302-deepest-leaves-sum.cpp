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
        vector<int> levelOrder;
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int>mpp;
        int curr_level = 0;
        
        while(!q.empty()){
            int size = q.size();
            TreeNode* temp;
            for(int i=0;i<size;i++){
                mpp[curr_level]++;
                temp = q.front();
                levelOrder.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
            curr_level++;
        }
        
        int sum = 0;
        int node = 0;
        
        for(int i=levelOrder.size()-1;i>=0 && node<mpp[curr_level-1];i--){
            sum += levelOrder[i];
            node++;
        }
        
        return sum;
    }
};
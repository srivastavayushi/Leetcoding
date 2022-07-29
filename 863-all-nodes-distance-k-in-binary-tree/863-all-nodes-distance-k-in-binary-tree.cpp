/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(unordered_map<int,vector<int>>&adj, TreeNode* temp){
        if(!temp) return;
            if(temp->left){
                adj[temp->val].push_back(temp->left->val);
                adj[temp->left->val].push_back(temp->val);
                dfs(adj,temp->left);
            }
            if(temp->right){
                adj[temp->val].push_back(temp->right->val);
                adj[temp->right->val].push_back(temp->val);
                dfs(adj,temp->right);
            } 
    }
    void bfs(vector<int>&res, int k, unordered_map<int,vector<int>>&adj, int val, vector<bool>&vis){
        if(k==0){
            res.push_back(val);
            return;
        }
        vis[val] = true;
        
        for(auto it:adj[val]){
            if(!vis[it]){
                bfs(res,k-1,adj,it,vis);
            }
        }
        
        return;
        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        if(!root) return res;
        
        TreeNode* temp = root;
        unordered_map<int,vector<int>>adj;
        
        dfs(adj,temp);
        if(adj.size()<k) return res;
        vector<bool>vis(adj.size(),false);
        bfs(res,k,adj,target->val,vis);
        
        return res;
    }
};
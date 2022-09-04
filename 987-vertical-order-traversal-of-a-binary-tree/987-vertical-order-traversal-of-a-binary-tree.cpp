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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // {node,{vertical,horizontal}}
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
            
        // {vertical,{level -> multiset (so that same level & vertical nodes are sorted)}}
        map<int,map<int,multiset<int>>>nodes;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            TreeNode* node = it.first;
            int v = it.second.first;
            int h = it.second.second;
            
            nodes[v][h].insert(node->val);
            
            if(node->left) q.push({node->left,{v-1,h+1}});
            if(node->right) q.push({node->right,{v+1,h+1}});
            
        }
        
        vector<vector<int>>res;
        
        for(auto it:nodes){
            vector<int>col;
            for(auto p:it.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            res.push_back(col);
        }
        
        return res;
    }
};
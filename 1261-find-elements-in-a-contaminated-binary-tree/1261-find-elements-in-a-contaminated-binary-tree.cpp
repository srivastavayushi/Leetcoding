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
private:
    unordered_map<int,int>nodes;
public:
    void recoverNode(TreeNode* root,int value){
        if(!root) return;
        
        root->val = value;
        nodes[value]++;
        if(root->left != NULL) recoverNode(root->left,2*value+1);
        if(root->right != NULL) recoverNode(root->right,2*value+2);
        
        return;
    }
    FindElements(TreeNode* root) {
        recoverNode(root,0);
    }
    
    bool find(int target) {
//         for(auto it : nodes){
//             cout <<it.first<<' '<<it.second<<endl;
//         }
//         cout<<"-------"<<endl;
        
        return nodes[target]>0 ? true : false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
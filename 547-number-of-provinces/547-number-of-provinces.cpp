class Solution {
private:
    void dfs(int node, vector<int>&vis, unordered_map<int,vector<int>>&adj){
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>>adj;
        
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j] == 1) adj[i].push_back(j);
            }
        }
        
        int res = 0;
        vector<int>vis(isConnected.size(),0);
        
        for(auto it : adj){
            if(!vis[it.first]){
                dfs(it.first,vis,adj);
                res++;
            }
        }
        
        return res;
    }
};
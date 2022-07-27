class Solution {
public:
    void dfs(vector<int>&vis,unordered_map<int,vector<int>>&mpp, int node){
        vis[node] = 1;
        for(auto it : mpp[node]){
            if(vis[it] == 1) continue;
            dfs(vis,mpp,it);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>>mpp;
        
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j] == 1) mpp[i].push_back(j);
            }
        }
        
        int res = 0;
        vector<int>vis(isConnected.size(),0);
        
        for(auto it:mpp){
            if(vis[it.first]==1) continue;
            dfs(vis,mpp,it.first);
            res++;
        }
        
        return res;
    }
};
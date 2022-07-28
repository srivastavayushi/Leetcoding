class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>>graph;
        
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool>vis(n+1,false);
        queue<int>q;
        q.push(start);
        vis[start] = true;
        
        while(!q.empty()){
            int curr = q.front();
            if(curr == end) return 1;
            q.pop();
            
            for(auto it:graph[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return 0;
        
    }
};
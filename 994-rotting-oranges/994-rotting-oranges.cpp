// this question tells us when to use BFS and when to use DFS
// BFS - since we have to travel to rotten oranges SIMELTANEOUSLY
// Watch striver video at 7:00

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        int vis[row][col];
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){ 
                
                // vis array index = 2 && push at time 0 which oranges are rotten
                if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        
        
        int time = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();

            // go to every index near curr idx
            for(int k=0;k<4; k++){
                int nrow = drow[k] + r;
                int ncol = dcol[k] + c;
            
            if(nrow >= 0 && nrow < row && ncol >=0 && ncol < col && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol] = 2;
                }
                
            }
            
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){ 
                if(grid[i][j]==1 && vis[i][j] != 2) return -1;
            }
        }
        
        return time;
                
    }
};
class Solution {
private:
    void markVisited(vector<vector<char>>&grid, int i, int j, int rows, int cols){
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j] != '1') return;
        
        grid[i][j] = '2';
        
        markVisited(grid,i+1,j,rows,cols);
        markVisited(grid,i,j+1,rows,cols);
        markVisited(grid,i-1,j,rows,cols);
        markVisited(grid,i,j-1,rows,cols);
        
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j] == '1'){
                    
                    markVisited(grid,i,j,grid.size(),grid[0].size());
                    ans += 1;
                }
                
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int cherryPickupHelper(int i, int j1, int j2,int row, int col, vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(j1<0 || j2<0 || j1>=col || j2>=col) return -1e8;
        if(i==row-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = 0;
        
        for(int a=-1; a<=1; a++){
            for(int b=-1; b<=1; b++){
                if(j1==j2) maxi = max(maxi, grid[i][j1] + cherryPickupHelper(i+1,j1+a,j2+b,row,col,grid,dp));
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + cherryPickupHelper(i+1,j1+a,j2+b,row,col,grid,dp));
            }
        }
        dp[i][j1][j2] = maxi;                        
        return maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>>dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        return cherryPickupHelper(0,0,cols-1,rows,cols,grid,dp);
    }
};
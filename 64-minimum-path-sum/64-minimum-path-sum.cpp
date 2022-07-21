class Solution {
public:
    int helper(vector<vector<int>>&dp,vector<vector<int>>&grid,int i, int j){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = grid[i][j] += min(helper(dp,grid,i-1,j), helper(dp,grid,i,j-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int> > dp(grid.size(),vector<int>(grid[0].size(),-1));
        return helper(dp,grid,grid.size()-1,grid[0].size()-1);
    }
};
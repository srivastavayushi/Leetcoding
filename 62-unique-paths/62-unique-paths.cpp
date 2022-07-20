class Solution {
// 
public:
    int helper(int row,int col, int m, int n, vector<vector<int>>&dp){
        if(row>=m || col>=n) return 0;
        if(row==m-1 && col==n-1) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col]= helper(row+1,col,m,n,dp) + helper(row,col+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int> (n, 1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        // return helper(0,0,m,n,dp);
        return dp[m-1][n-1];
    }
};
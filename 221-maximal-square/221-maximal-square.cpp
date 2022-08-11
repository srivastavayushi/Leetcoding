class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        int res = 0;
        
        // every cell of dp matrix represents maximal square matrix that can be formed using that cell
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0) dp[i][j] = matrix[i][j] - '0';
                res = max(dp[i][j],res);
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    int mini = min(dp[i-1][j], dp[i-1][j-1]);
                    dp[i][j] = 1 + min(mini,dp[i][j-1]);
                }
                res = max(dp[i][j],res);
            }
        }
        
        return res*res;
        
    }
};
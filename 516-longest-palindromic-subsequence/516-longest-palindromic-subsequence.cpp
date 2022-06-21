class Solution {
private:
    int lcs(string X, string Y, int m, int n){
        int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0)  dp[i][j]=0;
            }
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(X[i-1]==Y[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    
        return dp[m][n];
        
    }
public:
    int longestPalindromeSubseq(string s) {
        string original = s;
        reverse(s.begin(),s.end());
        return lcs(original,s,original.size(),s.size());
    }
};
class Solution {
public:
    int dp[1005][1005];
    
    void lcs (string s1, string s2, int m, int n) 
    {
        for(int i = 0; i <= m; i++)
            dp[i][0] = 0;
        for(int j = 0; j <= n; j++)
            dp[0][j] = 0;
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        lcs(str1, str2, m, n);
        int i = m, j = n;
        string res = "";
        while(i != 0 and j != 0)
        {
            if(str1[i-1] == str2[j-1]) {
                res += str1[--i];
                --j;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) 
                    res += str1[--i];
                else
                    res += str2[--j];
            }
        }
        while(i != 0)
            res += str1[--i];
        while(j != 0)
            res += str2[--j];
        reverse(res.begin(), res.end());
        return res;
    }
};
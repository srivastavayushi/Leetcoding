class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        // every cell in matrix suggests : agar is index ko buy/not buy kia to kitta price hoga
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        
        dp[n][1] = dp[n][0] = 0;
        
        for(int i=n-1;i>=0;i--){
            // buy - 1 and !buy - 0
            dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
        }
        
        return dp[0][1];
    }
};
class Solution {
public:
    int helper(int idx, bool buy, vector<int>&prices, int cap, vector<vector<vector<int>>>&dp){
        // base case : even if we can sell, we wont get a profit out of it at last index
        if(idx==prices.size() || cap==0 ) return 0;
        
        if(dp[idx][cap][buy] != -1) return dp[idx][cap][buy];
        
        if(buy){
            // if we can buy it -> either we buy so -prices or we dont
            dp[idx][cap][buy] = max(-prices[idx] + helper(idx+1,!buy,prices,cap,dp), helper(idx+1,buy,prices,cap,dp));
        }else{
            // if we sell it -> either we sell it so add profit or we dont
            dp[idx][cap][buy] = max(prices[idx] + helper(idx+1,!buy,prices,cap-1,dp), helper(idx+1,buy,prices,cap,dp));
        }
        return dp[idx][cap][buy];
    }
    int maxProfit(vector<int>& prices) {
        int cap = 2;
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return helper(0,true,prices,cap,dp);
    }
};
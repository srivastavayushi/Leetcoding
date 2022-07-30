class Solution {
public:
    int helper(int idx, bool buy, vector<int>&prices,vector<vector<int>>&dp){
        // base case : even if we can sell, we wont get a profit out of it at last index
        if(idx==prices.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy){
            // if we can buy it -> either we buy so -prices or we dont
            dp[idx][buy] = max(-prices[idx] + helper(idx+1,!buy,prices,dp), helper(idx+1,buy,prices,dp));
        }else{
            // if we sell it -> either we sell it so add profit or we dont
            dp[idx][buy] = max(prices[idx] + helper(idx+1,!buy,prices,dp), helper(idx+1,buy,prices,dp));
        }
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return helper(0,true,prices,dp);
    }
};
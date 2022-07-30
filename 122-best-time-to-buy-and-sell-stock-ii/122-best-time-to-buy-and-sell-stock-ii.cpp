class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
    
        int buy = 0;
        int notbuy = 0;
        
        for(int i=n-1;i>=0;i--){
            int temp_buy = max(-prices[i] + notbuy, buy);
            int temp_notbuy = max(prices[i] + buy, notbuy);
            buy = temp_buy;
            notbuy = temp_notbuy;
            
        }
        
        return buy;
    }
};
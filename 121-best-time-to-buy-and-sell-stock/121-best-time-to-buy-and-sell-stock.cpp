class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min = prices[0];
        
        for(int i=1;i<prices.size();i++){
            int diff = prices[i]-min;
            
            if(diff>profit){
                profit = diff;
            }
            
            if(prices[i]<min){
                min=prices[i];
            }
            
        }
        return profit;
    }
};
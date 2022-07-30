class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;
        for(auto it:prices){
            mini = min(it,mini);
            profit = max(profit,it-mini);
        }
        
        return profit;
    }
};
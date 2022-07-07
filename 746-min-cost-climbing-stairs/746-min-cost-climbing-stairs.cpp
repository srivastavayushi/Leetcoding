class Solution {
private:
    unordered_map<int,int>mpp;
public:
    int minCost(int n, vector<int>cost){
        if(n<0) return mpp[n]=0;
        if(n==0 || n==1) return mpp[n]=cost[n];
        
        if(mpp[n] != 0) return mpp[n];
        
        return mpp[n] = cost[n] + min(minCost(n-1,cost),minCost(n-2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(minCost(n-1,cost),minCost(n-2,cost));
    }
};
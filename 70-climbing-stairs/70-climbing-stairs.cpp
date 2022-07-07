class Solution {
public:
    unordered_map<int,int>dp;
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        
        if(dp[n] != 0) return dp[n];
        return dp[n]=climbStairs(n-1) + climbStairs(n-2);
        
    }
};
class Solution {
public:
    int solve(vector<int>&nums,int idx,vector<int>&dp){
        if(idx>=nums.size()-1) return 0;
        int minJumps = 10001;
        if(dp[idx] != 10001) return dp[idx];
        for(int i=1;i<=nums[idx];i++){
            minJumps = min(minJumps, 1 + solve(nums, idx + i, dp));
        }
        return dp[idx] = minJumps;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 10001);
        return solve(nums,0,dp);
    }
    
};
class Solution {
public:
    vector<int> dp;
    bool jump(vector<int>&nums,int idx){
        if(idx == nums.size()-1) return true;
        if(idx>=nums.size()) return false;
        
        if(dp[idx] != -1) return dp[idx];
        
        for(int i=1;i<=nums[idx];i++){
            if(jump(nums,idx+i)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        dp.assign(nums.size(),-1);
        bool res = jump(nums,0);
        // for(auto it : mpp) cout<<it.first<<' '<<it.second<<endl;
        // cout<<"----"<<endl;
        return res;
    }
};

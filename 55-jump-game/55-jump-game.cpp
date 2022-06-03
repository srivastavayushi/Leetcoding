class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        
        int reachableIdx = 0;
        
        for(int i=0;i<=n;i++){
            if(reachableIdx<i){
                return false;
            }
            if(reachableIdx<=(nums[i]+i)){
               reachableIdx = nums[i]+i; 
            }
        }
        
        return true;
    }
};
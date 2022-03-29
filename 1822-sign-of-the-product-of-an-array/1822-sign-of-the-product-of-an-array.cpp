class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int res = 1;
        int k_negative = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                res = 0;
            }
            if(nums[i]<0){
                k_negative++;
            }
            
        }
        
        if(res == 0){
            return 0;
        }else if(k_negative % 2 == 0){
            return 1;
        }else{
            return -1;
        }
    }
};
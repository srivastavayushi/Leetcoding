class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        long long len = 0;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==0 && i==nums.size()-1){
                res = res + ((len+1) * (len+2))/2;
                return res;
            }else if(nums[i] == 0){
                len++;

            }else if(nums[i] != 0 && len > 0){
                res = res + ((len*(len+1))/2);
                len = 0;
            }
        }
        return res;
    }
};
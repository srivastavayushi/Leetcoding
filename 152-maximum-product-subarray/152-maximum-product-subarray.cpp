class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>suffix(nums.size());
        suffix[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            if(nums[i+1] != 0){
                suffix[i] = nums[i]*suffix[i+1];
            }else{
                suffix[i] = nums[i];
            }
            
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] != 0){
                nums[i] *= nums[i-1];
            }else{
                nums[i] = nums[i];
            }
            
        }
        int maximum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maximum = max(maximum,max(suffix[i],nums[i]));
        }
        return maximum;
    }
};
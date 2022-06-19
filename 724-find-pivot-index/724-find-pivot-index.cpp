class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int leftSum = 0;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            if(2*leftSum==(sum-nums[i])){
                return i;
            }
            leftSum += nums[i];
        }
        
        return -1;
    }
};
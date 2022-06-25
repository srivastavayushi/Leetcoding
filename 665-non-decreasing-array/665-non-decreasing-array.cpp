class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int times = 0;
        for(int i=1;i<nums.size() && times<=1;i++){
            if(nums[i-1]>nums[i]){
                times++;
                if(i-2<0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return times<=1;
    }
};

    
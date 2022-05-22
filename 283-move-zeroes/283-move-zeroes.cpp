class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1){
            return;
        }
        int l=0;
        int h=1;
        int size = nums.size()-1;
        
        while(h<=size){
            // cout<<nums[h]<<" "<<nums[l]<<" | ";
            if(nums[l]==0 && nums[h]==0){
                h++;
            }else if(nums[l]==0 && nums[h] != 0){
                swap(nums[h],nums[l]);
                l++;
                h++;
            }else{
                h++;
                l++;
            }
        }
        return;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        int r=0;
        int size=nums.size();
        while(r<size){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }else{
                nums[r]=0;
            }
            r++;
        }
    }
};
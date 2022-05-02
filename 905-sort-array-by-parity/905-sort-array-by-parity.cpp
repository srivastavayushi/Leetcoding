class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int r=0;
        int size=nums.size();
        while(r<size){
            if(nums[r]%2==0){
                swap(nums[l],nums[r]);
                l++;
            }
            r++;
        }
        return nums;
    }
};
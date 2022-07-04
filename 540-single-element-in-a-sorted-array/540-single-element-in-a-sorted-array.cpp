class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        
        while(l<h){
            int mid = (l+h)/2;
            if((mid%2 == 0 && nums[mid] == nums[mid+1]) || (mid%2 != 0 && nums[mid] == nums[mid-1])) l=mid+1;
            else h=mid;
        }
        
        return nums[l];
    }
};
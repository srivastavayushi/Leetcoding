class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int l=0;
        int r=1;
        
        int size = nums.size();
        
        if(size==0){
            return 0;
        }
        
        while(r < size){
             if(nums[l]==nums[r]){
                r++;
            }else {
              swap(nums[l+1],nums[r]);
                 l++;
                 r++;
            }
        }     
        return l+1;
    }
};
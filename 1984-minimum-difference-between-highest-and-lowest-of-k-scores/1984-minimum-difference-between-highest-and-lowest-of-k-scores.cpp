class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        if(nums.size()==1){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int l=0;
        int r=k-1;
        
        int min = INT_MAX;
        
        while(r<=(nums.size()-1)){
            if((nums[r]-nums[l])<min){
               min = nums[r]-nums[l]; 
            }
            l++;
            r++;
        }
        
        return min;
    }
};
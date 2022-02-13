class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>copy(nums.size());
        
        copy[nums.size()-1]=nums[nums.size()-1];
        
        for(int i=nums.size()-2;i>=0;i--){
            copy[i]=copy[i+1]+nums[i];
        }
        
        if(copy[1]==0){
            return 0;
        }
        
        copy[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int res=nums[i]+copy[i-1];
            if(res==copy[i]){
                return i;
            }else{
                copy[i]=res;
            }
        }
        
        return -1;
    }
};
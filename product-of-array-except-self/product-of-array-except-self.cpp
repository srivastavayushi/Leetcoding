class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        
        result.push_back(nums[0]);    
        
        for(int i=1;i<nums.size();i++){
            result.push_back(nums[i]*result[i-1]);
        }
        
        int right_product = 1;
        
        for(int i=nums.size()-1;i>=0;i--){
            
            if(i==nums.size()-1){
                result[i]=result[i-1];
            }else if(i==0){
                result[i]=right_product;
            }else{
                result[i]=result[i-1]*right_product;
                
            }
            right_product=right_product*nums[i];
        }
        
        return result;
        }
};
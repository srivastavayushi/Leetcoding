class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int>res(nums.size());
        
        int l=0;
        int r=nums.size()-1;
        
        for(int i=res.size()-1;i>=0;i--){
            
           if(abs(nums[l])<abs(nums[r])){
              res[i]=nums[r]*nums[r--]; 
           }else{
               res[i]=nums[l]*nums[l++];
           }
        }
        
        return res;         
    }
};
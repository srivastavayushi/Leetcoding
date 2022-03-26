class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int k = nums.size();
        
        for(int i=k;i<2*k;i++){
            nums.push_back(nums[i-k]);
        }
        
        return nums;
    }
};
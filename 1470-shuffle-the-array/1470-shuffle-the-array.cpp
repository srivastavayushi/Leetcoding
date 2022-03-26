class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> res;
        int s=0;
        int l=n;
        
        while(l<nums.size()){
            res.push_back(nums[s]);
            res.push_back(nums[l]);
            s++;
            l++;
        }
        
        
        return res;
    }
};
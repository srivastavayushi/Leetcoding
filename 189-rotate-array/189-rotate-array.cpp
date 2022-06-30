class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        vector<int>v;
        int index = nums.size() - k;
        for(int i=nums.size()-k;i<nums.size();i++) v.push_back(nums[i]);
        for(int i=0;i<index;i++) v.push_back(nums[i]);
        nums = v;
        return;
    }
};
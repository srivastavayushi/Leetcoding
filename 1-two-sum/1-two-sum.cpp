class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        
        for(int i=0;i<nums.size();i++){
            int b = nums[i];
            int a = target - b;
            if (mpp.count(a)) return {mpp[a], i};
            mpp[b] = i;
        }
        return {};
    }
};
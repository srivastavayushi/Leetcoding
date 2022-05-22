class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev = -1;
        for(auto i : nums){
            if(prev == i){
                return prev;
            }
            prev = i;
        }
        return -1;
    }
};
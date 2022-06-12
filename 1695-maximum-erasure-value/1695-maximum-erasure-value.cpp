class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>hset;
        int window = 0;
        int res = 0;
        
        for(int i=0,j=0; j<nums.size();j++){
            while(hset.find(nums[j]) != hset.end()){
                hset.erase(nums[i]);
                window -= nums[i];
                i++;
            }
            
            hset.insert(nums[j]);
            window += nums[j];
            res = max(window,res);
        }
        
        return res;
    }
};
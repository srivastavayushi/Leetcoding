class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size() == 1) return nums;
        
        unordered_map<int,int> mpp;
        vector<vector<int>> hash;
        
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        
        for(auto it : mpp){
            vector<int>temp;
            temp.push_back(it.second);
            temp.push_back(it.first);
            hash.push_back(temp);
        }
        
        sort(hash.begin(),hash.end());
        
        vector<int>res;
        
        while(k != 0){
            res.push_back(hash[hash.size()-k][1]);
            k--;
        }
        
        return res;
    }
};
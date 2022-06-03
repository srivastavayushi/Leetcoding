class Solution {
public:
    void printSubset(vector<int>nums, vector<vector<int>> &res, int n, int index,vector<int>&temp){
        if(index == n){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        printSubset(nums,res,n,index+1,temp);
        temp.pop_back();
        printSubset(nums,res,n,index+1,temp);
        return;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        int n = nums.size();
        printSubset(nums,res,n,0,temp);
        return res;
        
    }
};
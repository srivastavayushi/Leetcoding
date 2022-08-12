class Solution {
private:
    void helperPermute(vector<vector<int>>&res, vector<int>&permutation, int freq[], int n,vector<int>& nums){
        if(permutation.size() == n){
            res.push_back(permutation);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!freq[i]){
                permutation.push_back(nums[i]);
                freq[i] = 1;
                helperPermute(res,permutation,freq,n,nums);
                
                // backtracking
                permutation.pop_back();
                freq[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>>res;
        vector<int>permutation;
        int freq[size];
        
        for(int i=0;i<size;i++) freq[i] = 0;
        
        helperPermute(res,permutation,freq,size,nums);
        return res;
        
    }
};
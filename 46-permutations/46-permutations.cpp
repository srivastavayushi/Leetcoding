class Solution {
private:
    void helperPermute(vector<int>&ds, int freq[], vector<int>nums, vector<vector<int>> &res, int n){
        if(ds.size()==n){
            res.push_back(ds);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                helperPermute(ds,freq,nums,res,n);
                ds.pop_back();
                freq[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int>ds;
        int freq[n];
        for(int i=0;i<n;i++) freq[i]=0;
        helperPermute(ds,freq,nums,res,n);
        return res;
        
    }
};
class Solution {
public:
    void reverse(vector<int>& num, int low,int high){
        while(low<high){
            swap(num[low],num[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
//         if(k==0){
//             return;
//         }
        
//         int temp = nums[nums.size()-1];
//         nums.pop_back();
//         reverse(nums.begin(),nums.end());
//         nums.push_back(temp);
//         reverse(nums.begin(),nums.end());
        
//         rotate(nums,k-1);
        
        if(nums.size()==1){
            return;
        }
        int n = (int)nums.size();
        k=k%n;
        
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
    }
};
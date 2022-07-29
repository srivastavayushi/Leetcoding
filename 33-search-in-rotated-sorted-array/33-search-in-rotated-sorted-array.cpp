class Solution {
public:
    int binarySearch(int start, int end, int target, vector<int>& nums){
        // cout<<start<<end<<endl;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]>target) end=mid-1;
            else start = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        int idx = 0;
        for(int i=0;i<=nums.size()-2;i++){
            if(nums[i]>nums[i+1]) idx = i;
        }
        
        if(nums[idx]==target) return idx;
        
        if(target>nums[nums.size()-1]) return binarySearch(0,idx-1,target,nums);
        else return binarySearch(idx+1,nums.size()-1,target,nums);
        
        return -1;
        
    }
};
class Solution {
private:
    bool search(vector<int>& nums, int target, int l, int &index){
        int low = l;
        int high = nums.size()-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                index = mid;
                return true;
            }
            
            if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        return false;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++){
            int index;
            if(search(numbers,target-numbers[i],i+1, index)) return {i+1,index+1};
        }
        return {};
    }
};
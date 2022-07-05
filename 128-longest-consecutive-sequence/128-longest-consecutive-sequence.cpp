class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        vector<vector<int>> mapp;
        
        for(auto it:mpp){
            mapp.push_back({it.first,it.second});
            // cout<<it.first<<' '<<it.second<<endl;
        }
        
        // cout<<"----"<<endl;
        int curr_count = 1;
        int max_count = INT_MIN;
        
        for(int i=1;i<mapp.size();i++){
            if(abs(mapp[i][0]-mapp[i-1][0]) == 1) curr_count++;
            else{
                max_count = max(curr_count,max_count);
                curr_count = 1;
            }
        }
        
        if(max_count<curr_count) return curr_count;
            
        return max_count;
    }
};
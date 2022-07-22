class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<vector<int>>vec;
        unordered_map<int,int>mpp;
        for(auto it : arr) mpp[it]++;
        for(auto it : mpp) vec.push_back({it.second,it.first});
        sort(vec.begin(),vec.end());
        int curr_size = 0;
        int ans = 0;
        for(int i=vec.size()-1;i>=0;i--){
             curr_size += vec[i][0];
             ans++;
             if(curr_size >= arr.size()/2) return ans;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        merged.push_back({intervals[0][0],intervals[0][1]});
        
        for(auto interval:intervals){
            if(merged.empty() || merged.back()[1]<interval[0]){
                merged.push_back(interval);
            }else{
                merged.back()[1] = max(merged.back()[1],interval[1]);
            }
        }
        
        return merged;
    }
};
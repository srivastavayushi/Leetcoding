class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        for(auto it:arr){
            mpp[it]++;
        }
        
        vector<vector<int>>freq;
        
        for(auto it:mpp){
            freq.push_back({it.second,it.first});
        }
        
        sort(freq.begin(),freq.end());
        
        int i = 0;
        for(i=0;i<freq.size();i++){
            if(k==0) return freq.size() - i;
            if(k<0) return freq.size() - i +1;
            k -= freq[i][0];
        }
        
        if(k==0) return 0;
        
        return k<0 ? freq.size() - i +1 : 0;
    }
};
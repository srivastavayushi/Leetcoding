class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
       
        long res = 0, mod = pow(10, 9) + 7;
        unordered_map<int,long>mpp;
        sort(arr.begin(),arr.end());
        
        
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]] = 1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    mpp[arr[i]] = (mpp[arr[i]] + mpp[arr[j]] * mpp[arr[i] / arr[j]]) % mod;
                        
                }
            }
            res = (res + mpp[arr[i]]) % mod;
        }
        return res;
    }
};
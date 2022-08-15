class Solution {
public:
    int romanToInt(string s) {
        int n = s.length()-1;
        unordered_map<char,int>mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        int res = mpp[s[n]];
        
        for(int i=n-1;i>=0;i--){
            if(mpp[s[i]] < mpp[s[i+1]]) res -= mpp[s[i]];
            else res += mpp[s[i]];
        }
        
        return res;
    }
};
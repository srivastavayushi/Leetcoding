class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0;
        
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>mpp;
            mpp[s[i]]++;
            int j=i+1;
            while(j<s.size() && mpp[s[j]]<1){
               // cout<<s[j]<<endl;
                mpp[s[j]]++;
                j++;
            }
            int size = mpp.size();
            
            maxLen = max(size,maxLen);
        }
        return maxLen;
    }
};
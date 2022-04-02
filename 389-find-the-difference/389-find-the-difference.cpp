class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char res = 0;
        int i = 0;
        for(i;i<s.length();i++){
            res ^= s[i];
            res ^= t[i];
        }
        res ^= t[i];
        return res;
    }
};
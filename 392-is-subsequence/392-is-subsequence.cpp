class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.length() > t.length()) return false;
        
        int j=0;
        
        for(int i=0;i<t.length() && j<s.length();i++){
            if(s[j]==t[i]) j++;
        }
        
        return (j==s.length());
    }
};
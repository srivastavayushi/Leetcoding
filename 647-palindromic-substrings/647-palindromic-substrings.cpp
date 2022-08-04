class Solution {  
private:
    bool isPalindrome(int start, int end, string s){
        while(start<=end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        
        return true;
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalindrome(i,j,s)) count++;
            }
        }
        
        return count;
    }
};
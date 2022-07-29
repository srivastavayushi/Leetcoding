class Solution {
public:
    string helper(int &pos,string s){
        int num = 0;
        string word = "";
        
        for(;pos<s.length();pos++){
            char curr = s[pos];
            if(curr == '['){
                string curr = "";
                curr = helper(++pos,s);
                for(; num>0;num--) word += curr;
                
            }else if(s[pos]<='9' && s[pos]>='0'){
                num = num * 10 + curr - '0';
                
            }else if(curr == ']'){
                return word;
            }else{
                word += curr;
            }
        }
        return word;
    }
    string decodeString(string s) {
        int pos = 0;
        return helper(pos,s);
    }
};
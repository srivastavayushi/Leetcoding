class Solution {
public:
    string reverseWords(string str) {
        int left = 0;
        int right = str.length()-1;
        
        string temp="";
        string res="";
        
        while(left<=right){
            char ch = str[left];
            if(ch != ' ') temp+=ch;
            else if(ch == ' ' && temp!=""){
                if(res != "") res = temp + " " + res;
                else res = temp;
                temp = "";
            }
            left++;
        }
        
        if(temp!=""){
            if(res != "") res = temp + ' ' + res;
            else res = temp;
        }
    
        return res;
    }
};
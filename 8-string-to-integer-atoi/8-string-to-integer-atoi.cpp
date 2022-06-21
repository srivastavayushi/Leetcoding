class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0) return 0;
        int i=0;
        
        while(i<s.size() && s[i] == ' '){
            i++;
        }
 
        long ans = 0;
        int MAX = INT_MAX;
        int MIN = INT_MIN;
        int sign = 1;
        
        s = s.substr(i);
        
        if(s[0]=='-') sign=-1;
        
        i = (s[0]=='-' ||s[0]=='+') ? 1 : 0;
        
        while(i<s.length()){
            if(s[i]==' ' || !isdigit(s[i])) break;
            
            ans = ans*10 + s[i] - '0';
            if(sign==-1 && -1*ans < INT_MIN) return MIN;
            if(sign==1 && ans>MAX) return MAX;
            
            i++;
        }
        return (int)(ans*sign);
    }
};
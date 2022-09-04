class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        
        string s = "11";
        
        for(int i=3;i<=n;i++){
            string temp = "";
            
            // to count the last 1 in "1211"
            s += '$';
            int times = 1;
            
            for(int j=1;j<s.length();j++){
                if(s[j] != s[j-1]){
                    temp+=to_string(times);
                    temp+=s[j-1];
                    times=1;
                    
                }else times++;
            }
            
            s=temp;
        }
        
        return s;
        
    }
};
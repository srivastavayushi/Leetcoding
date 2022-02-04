class Solution {
public:
    string largestOddNumber(string num) {
        
        if(num[num.length()-1]%2 != 0){
            return num;
        }
        
        string res=""; 
        
        for(int i=num.length()-1;i>=0;i--){
            
            string s(1,num[i]);
            int iinum = stoi(s);
            
            if(iinum%2 != 0){
                res=num.substr(0,i+1);
                return res;
            }
            
        }
        
        return res;
    }
};
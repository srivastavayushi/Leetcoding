class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        
        int c3 = 0;
        int c5 = 0;
        
        
        for(int i=1;i<=n;i++){
            string d = "";
            c3++;
            c5++;
           if(c3==3){
               d=d+"Fizz";
               c3=0;
           } 
            if(c5==5){
                d=d+"Buzz";
                c5=0;
            }
            
            if(d!=""){
                res.push_back(d);
            }else{
                res.push_back(to_string(i));
            }
        }
        
        return res;
    }
};
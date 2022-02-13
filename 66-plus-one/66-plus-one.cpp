class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int h=digits.size()-1;
        
        for(int i=h;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }else{
                digits[i]++;
                return digits;
            }
        }
        
        digits[0]=1;
        digits.push_back(0);
        return digits;
        
    }
};
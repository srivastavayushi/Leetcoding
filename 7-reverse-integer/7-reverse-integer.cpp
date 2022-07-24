class Solution {
public:
    int reverse(int k) {
        long int x = k;
        int sign = 1;
        if(x<0){
            sign = -1;
            if(-1*x>INT_MAX || -1*x<INT_MIN+1) return 0;
            x = -1*x;
        }
        vector<long int>temp;
        
        while(x>0){
            temp.push_back(x%10);
            x = x/10;
        }
        
        long int res = 0;
        
        std::reverse(temp.begin(),temp.end());
        
        for(int i=0;i<temp.size();i++){
            if(temp[i]*pow(10,i)>INT_MAX || temp[i]*pow(10,i)<INT_MIN) return 0;
            res += temp[i]*pow(10,i);
        }
        res *= sign;
        // cout<<res<<endl;
        return (INT_MIN<res && INT_MAX>res) ? int(res) : 0;
    }
};
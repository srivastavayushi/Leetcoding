class Solution {
public:
    int subtractProductAndSum(int n) {
        int add=0;
        int prod=1;
        while(n>0){
            int k = n%10;
            add += k;
            prod *= k;
            n/=10;
            
        }
        return (prod-add);
    }
};
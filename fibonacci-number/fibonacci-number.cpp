class Solution {
public:
    unordered_map<int,int>m;
    int fib(int n) {
        if(m.count(n) != 0){
            return m[n];
        }
        if(n<=1){
            return n;
        }
        
        int res = fib(n-1) + fib(n-2);
        m[n] = res;
        return res;
    }
};
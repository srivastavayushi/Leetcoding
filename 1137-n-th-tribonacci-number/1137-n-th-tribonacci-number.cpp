class Solution {
public:
    unordered_map<int,int>m;
    int tribonacci(int n) {
        if(m.count(n) != 0) return m[n];
        
        if(n == 0 || n == 1) return n;
        if(n== 2) return 1;
        
        return m[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};
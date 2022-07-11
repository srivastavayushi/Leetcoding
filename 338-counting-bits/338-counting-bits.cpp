class Solution {
public:
    void solve(int n, vector<int>&res){
        if(res.size()==n) return;
        res[n] = n%2 + res[n/2];
        solve(n+1,res);
        return;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        if(n==0) return res;
        res[1]=1;
        if(n==1) return res;
        res[2]=1;
        if(n==2) return res;
        solve(3,res);
        return res;
    }
};
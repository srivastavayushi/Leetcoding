class Solution {
public:
    void helper(vector<string>&res,string str,int remainLeft, int remainRight){
        if(remainLeft == 0 && remainRight == 0){
            res.push_back(str);
            return;
        }
        if(remainLeft>0) helper(res,str+'(',remainLeft-1,remainRight+1);
        if(remainRight>0) helper(res,str+')',remainLeft,remainRight -1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        helper(res,"",n,0);
        return res;
    }
};
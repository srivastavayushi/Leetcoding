class Solution {
private:
    void helper(vector<string>&res,string digits,int idx, unordered_map<char,vector<char>>&mpp, string curr){
        if(idx >= digits.size()){
            res.push_back(curr);
            return;
        }
        
        for(auto it : mpp[digits[idx]]){
            helper(res,digits, idx+1,mpp,curr+it);
        }
        
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits=="") return res;
        
        unordered_map<char,vector<char>>mpp;
        mpp['2'] = {'a','b','c'};
        mpp['3'] = {'d','e','f'};
        mpp['4'] = {'g','h','i'};
        mpp['5'] = {'j','k','l'};
        mpp['6'] = {'m','n','o'};
        mpp['7'] = {'p','q','r','s'};
        mpp['8'] = {'t','u','v'};
        mpp['9'] = {'w','x','y','z'};
        
        helper(res,digits,0, mpp,"");
        
        return res;
    }
};
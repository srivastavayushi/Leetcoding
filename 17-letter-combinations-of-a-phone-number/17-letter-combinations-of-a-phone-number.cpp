class Solution {
public:
    void letterCombinationsHelper(string digits, vector<string>&combinations, unordered_map<int,vector<char>>mpp, string combination,int index){
        if(combination.size() == digits.size()){
            combinations.push_back(combination);
            return;
        }
            for(auto it : mpp[digits[index]-'0']){
                combination.push_back(it);
                letterCombinationsHelper(digits,combinations,mpp,combination, index+1);
                combination.pop_back();
            }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if(digits.size() == 0) return combinations;
        unordered_map<int,vector<char>>mpp;
        mpp[2] = {'a','b','c'};
        mpp[3] = {'d','e','f'};
        mpp[4] = {'g','h','i'};
        mpp[5] = {'j','k','l'};
        mpp[6] = {'m','n','o'};
        mpp[7] = {'p','q','r','s'};
        mpp[8] = {'t','u','v'};
        mpp[9] = {'w','x','y','z'};
        string combination="";
        letterCombinationsHelper(digits,combinations, mpp, combination,0);
        return combinations;
    }
};
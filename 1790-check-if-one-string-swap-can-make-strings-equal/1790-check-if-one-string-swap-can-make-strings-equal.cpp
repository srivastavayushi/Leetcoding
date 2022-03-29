class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        unordered_map<int,char>mpp;
        unordered_map<int,char>mpp1;
        vector<int> index;
        
        for(int i=0;i<s1.length();i++){
            mpp[i]=s1[i];
        }
        
        for(int i=0;i<s2.length();i++){
            mpp1[i]=s2[i];
        }
        
        for(auto i : mpp){
            if(mpp1[i.first] != i.second){
                index.push_back(i.first);
            }
        }
        
        if((index.size() == 2) && (mpp[index[0]] == mpp1[index[1]]) && 
(mpp[index[1]] == mpp1[index[0]])){
    
            return true;
        }else if(index.size() == 0){
            return true;
        }
        return false;
    }
    
};
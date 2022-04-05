class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(t.length() != s.length()){
            return false;
        }
        unordered_map<int,int> umap;
        unordered_map<int,int> umap2;
        
        for(int i=0;i<s.length();i++){
            umap[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++){
            umap2[t[i]]++;
        }
        
        
        for (auto x : umap){
            if(x.second != umap2[x.first]){
                return false;
            }
        }        
        
        return true;
    }
};
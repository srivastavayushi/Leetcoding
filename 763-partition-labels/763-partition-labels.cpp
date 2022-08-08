class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        
        // contains last ocurrence index of every char
        for(int i=0;i<s.length();i++) mpp[s[i]] = i;
        
        //start idx of a part
        int start = -1;
        // end idx of part
        int end = 0;
        
        vector<int>partitions;
        
        for(int i=0;i<s.size();i++){
            end = max(end,mpp[s[i]]);
            if(end==i){
                partitions.push_back(end-start);
                start = end;
            }
        }
        
        return partitions;
    }
};
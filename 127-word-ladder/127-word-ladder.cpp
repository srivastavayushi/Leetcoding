class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 1;
        unordered_set<string>st(wordList.begin(), wordList.end());
        
        if(st.find(beginWord) != st.end()) st.erase(beginWord);
        cout<<"---"<<endl;
        for(auto it:st) cout<<it<<endl;
        
        if(st.find(endWord) == st.end()) return 0;
        
        queue<string>q;
        q.push(beginWord);
        
        int level = 0;
        
        while(!q.empty()){
            level+=1;
            
            int nodes = q.size();
            
            while(nodes--){
                string curr = q.front();
                q.pop();
                
                for(int j=0;j<curr.length();j++){
                    string temp = curr;
                    
                    // try all possible characters 
                    for(char c = 'a';c<='z';c++){
                        temp[j] = c;
                        
                        if(temp==curr) continue; // if same character then continue
                        if(temp==endWord) return level+1; // if endWord is found
                        if(st.find(temp) != st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};
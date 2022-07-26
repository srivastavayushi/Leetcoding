class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        // int res = 0;
        
        for(auto it : s){
            if(!st.empty() && (it == ')' && st.top()=='(')){
                st.pop();
                // res--;
                continue;
            }
            // res++;
            st.push(it);
        }
        
        // while(!st.empty()){
        //     res++;
        //     st.pop();
        // }
        
        return st.size();
    }
};
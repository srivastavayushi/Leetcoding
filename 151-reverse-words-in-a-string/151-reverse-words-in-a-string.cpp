class Solution {
public:
    string reverseWords(string str) {
        str+=' ';
        stack<string> st;
    string s="";
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            if(s.length()>0) st.push(s);
            s="";
        }else{
            s+=str[i];
        }
    }
    
    string res="";
    while(st.size()!=1){
        res += (st.top() + ' ');
        st.pop();
    }
    res+=st.top();
    return res;
    }
};
class Solution {
public:
    void reverse(vector<char>& s,int k,int size){
        if(k>=size/2){
            return;
        }
        swap(s[k],s[size-k-1]);
        reverse(s,k+1,size);
        return;
    };
    void reverseString(vector<char>& s) {
        if(s.size()==0){
            return;
        }
        int size = s.size();
        reverse(s,0,size);
        return;
    }
};
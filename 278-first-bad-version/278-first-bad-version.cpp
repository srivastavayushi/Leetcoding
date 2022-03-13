// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int l=1;
        unsigned int h=n;
        
        while(l<=h){
            
            unsigned int mid= (l+h)/2;
            
            if(isBadVersion(mid)==true && isBadVersion(mid-1)==false){
                return mid;
            }else if(isBadVersion(mid)==true){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return -1;
    }
};
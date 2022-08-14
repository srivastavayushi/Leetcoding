// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int l = 1;
        unsigned int r = n;
        
        while(l<=r){
            unsigned int mid = (l+r)/2;
            if(isBadVersion(mid)==true && isBadVersion(mid-1)==false) return mid;
            else if(isBadVersion(mid)) r = mid-1;
            else l = mid+1;
        }
        
        return -1;
    }
};
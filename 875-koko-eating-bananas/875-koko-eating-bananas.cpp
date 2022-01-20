class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right = *max_element(piles.begin(),piles.end());
        
        while(left<right){
            
            int middle = (left+right)/2;
            int hourSpent = 0;
            
            for(int pile:piles){
                hourSpent = hourSpent + pile/middle + (pile % middle != 0);
            }
            
            if(hourSpent<=h){
                right = middle;
            }else{
                left=middle+1;
            }
        }
        
        return right;
    }
};
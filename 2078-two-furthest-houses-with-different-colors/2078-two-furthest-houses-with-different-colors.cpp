class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        
        if(n==2){
            return 1;
        }
        
        int dist = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((colors[i] != colors[j]) && (abs(j-i)>dist)){
                    dist=abs(j-i);
                }
            }
        }
         return dist;
    }
};
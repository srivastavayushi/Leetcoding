class Solution {
public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        if(matrix == target) {     
            return true;
        }
        
        int degree = 3;
        
        while(degree --){
            for(int i=0; i<matrix.size();i++){
                for(int j=0;j<=i;j++){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        
            for(int i=0; i<matrix.size();i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
            
             if(matrix == target) return true;

        }
        
        return false;
    }
};
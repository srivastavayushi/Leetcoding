class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        bool col0 = true;
        
        for(int i=0;i<matrix.size();i++){ 
            if(matrix[i][0]==0){
                col0 = false;
            }
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        for(int i=rows-1;i>=0;i--){
            for(int j=columns-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col0==false){
                matrix[i][0]=0;
            }
        }
        
        return;
    }
};
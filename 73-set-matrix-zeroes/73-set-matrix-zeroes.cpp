class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        vector<int>dummy_row(rows,-1);
        vector<int>dummy_column(columns,-1);
        
        for(int i=0;i<matrix.size();i++){ 
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    dummy_row[i]=0;
                    dummy_column[j]=0;
                }
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(dummy_row[i]==0 || dummy_column[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        return;
    }
};
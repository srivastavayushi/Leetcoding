class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size()-1;
        int cols = matrix[0].size()-1;
        
        for(int i=rows-1;i>=0;i--){
            for(int j=0;j<=cols;j++){
                
                if(j==0) matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j+1]);
                else if(j==cols) matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j-1]);
                else{
                    int temp = min(matrix[i+1][j],matrix[i+1][j-1]);
                    temp = min(matrix[i+1][j+1],temp);
                    matrix[i][j] += temp;
                }
                
            }
            
        }
        
        int res = INT_MAX;
        
        for(auto it:matrix.front()) res = min(it,res);
        
        return res;
    }
};
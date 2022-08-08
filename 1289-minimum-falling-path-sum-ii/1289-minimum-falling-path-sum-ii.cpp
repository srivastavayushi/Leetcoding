class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rows = grid.size()-1;
        int cols = grid[0].size()-1;
        
        for(int i=rows-1;i>=0;i--){
            
            int minele = INT_MAX;
            int idx = 0;
            int minele_2 = minele;
            
            for(int k=0;k<=cols;k++){
                if(grid[i+1][k]<=minele){
                    minele_2 = minele;
                    minele = grid[i+1][k];
                    idx = k;
                }else{
                    minele_2 = min(minele_2,grid[i+1][k]);
                }
            }
            cout<<minele<<' '<<minele_2<<endl;
            
            for(int j=0;j<=cols;j++){
                if(j==idx) grid[i][j] += minele_2;
                else grid[i][j] += minele;
            }
            
            
        }
        
        int res = INT_MAX;
        
        for(auto it:grid.front()) res = min(it,res);
        
        return res;
    }
};
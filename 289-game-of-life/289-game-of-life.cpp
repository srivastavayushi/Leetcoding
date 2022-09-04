class Solution {
private:
    int live(int m,int n, vector<vector<int>>&board){
        
        int livecells = 0;
        
        int row[8] = {-1,0,1,0,-1,1,1,-1};
        int col[8] = {0,1,0,-1,1,1,-1,-1};
        
        for(int i=0;i<8;i++){
            int nrow = m+row[i];
            int ncol = n+col[i];
            if(nrow<0 || ncol<0 || nrow>=board.size() || ncol>=board[0].size()) continue;
            if(board[nrow][ncol]==1) livecells+=1;
        }
        
        return livecells;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>vec;
        vec = board;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                int ln = live(i,j,vec);
                
                // cout<< i << ' '<< j<< ':'<< live(i,j,vec)<<endl;
                
                if(board[i][j]==1){
                    if(ln<2 || ln>3) board[i][j] = 0;
                }else if(board[i][j]==0){
                    if(ln==3) board[i][j] = 1;
                }
            }
        }
             
    }
};

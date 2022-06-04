class Solution {
//     bool isSafe(vector<string>&board, int n, int col, int row){
        
//         int duprow = row;
//         int dupcol = col;
        
//         // upper left diagonal
//         while(row>=0 && col>=0){
//             if(board[row][col]=='Q') return false;
//             row--;
//             col--;
//         }
        
//         col = dupcol;
//         row = duprow;
        
//         // check left
//         while(col>=0){
//             if(board[row][col]=='Q') return false;
//             col--;
//         }
        
//         col = dupcol;
//         row = duprow;
        
//         // check lower right diagonal
//         while(row>=0 && col>=0){
//             if(board[row][col] == 'Q') return false;
//             col--;
//             row++;
//         }
        
//         return true;
//     }
                // if(isSafe(board,n,col,row)){
            //     board[row][col] = 'Q';
            //     solve(ans,board,n,col+1);
            //     board[row][col] = '.';
            // }
private: 
    void solve(vector<vector<string>>&ans, vector<string>&board, int n, int col, vector<int>&leftRow, vector<int>&upperLeft, vector<int>&lowerLeft){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowerLeft[row+col]==0 && upperLeft[(n-1)+(col-row)]==0){
                
                board[row][col] ='Q';
                leftRow[row]=1;
                lowerLeft[row+col]=1;
                upperLeft[(n-1)+(col-row)]=1;
                
                solve(ans,board,n,col+1, leftRow, upperLeft, lowerLeft);
                
                board[row][col] ='.';
                leftRow[row] = 0;
                lowerLeft[row+col] = 0;
                upperLeft[(n-1)+(col-row)] = 0;
                
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        vector<int> leftRow(n,0);
        vector<int> upperLeft((2*n-1),0);
        vector<int> lowerLeft((2*n-1), 0);
        
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(ans,board,n,0, leftRow, upperLeft, lowerLeft);
        
        return ans;
    }
};
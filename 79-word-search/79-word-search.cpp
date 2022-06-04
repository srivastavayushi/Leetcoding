class Solution {
    bool DFS(vector<vector<char>>& board,string word,int ptr, int row, int col){
        if(ptr == word.size()) return true;
        
        if(row<0 || col<0 || row >= board.size() || col>= board[0].size() || board[row][col] != word[ptr]) return false;
        
        board[row][col] = '.';
        
        bool status = DFS(board,word,ptr+1,row-1,col) ||
                   DFS(board,word,ptr+1,row,col-1) ||
                   DFS(board,word,ptr+1,row+1,col) ||
                   DFS(board,word,ptr+1,row,col+1);
        
        board[row][col] = word[ptr];
        
        return status; 
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0] && DFS(board,word,0,i,j)) return true;
            }
        }
        
        return false;
    }
};
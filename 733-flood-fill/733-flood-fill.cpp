class Solution {
private:
    void helper(vector<vector<int>>& image, int prev, int color, int i, int j){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] != prev) return;
        
        image[i][j] = color;
        
        
        helper(image,prev,color,i-1,j); // top
        helper(image,prev,color,i,j-1); // left
        helper(image,prev,color,i+1,j); // down
        helper(image,prev,color,i,j+1); // right
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor = image[sr][sc];
        
        if(color == prevColor) return image;
        
        helper(image,prevColor,color,sr,sc);
        return image;
    }
};
class UnionFind{    
public :    
    UnionFind(int sz) : root(sz), rank(sz), count(sz){
        for(int i=0;i<sz;i++){
            root[i]=i;
            rank[i]=1;
        }
    }
    
    int find(int i){
        if(i==root[i]){
            return i;
        }
        return root[i] = find(root[i]);
    }
    
    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY]){
                root[rootY] = rootX;
            }else if(rank[rootY]>rank[rootX]){
                root[rootX] = rootY;
            }else{
                root[rootX] = rootY;
                rank[rootY] += 1;
            }
            
            count--;
        }
    }
    
    int getCount(){
        return count;
    }
    
private :
        vector<int> rank;
        vector<int> root;
        int count;
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        if(isConnected.size()==0){
            return 0;
        }
        
        int rows = isConnected.size();
        
        UnionFind uf(rows);
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<rows;j++){
                if(isConnected[i][j]==1){
                    uf.unionSet(i,j);
                }
            }
        }
        
        return uf.getCount();
    }
};
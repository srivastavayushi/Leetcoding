// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101],int n, int col, int node, int color[]){
    for(int k=0;k<n;k++){
        if(k!=node && graph[k][node]==1 && color[k]==col){
            return false;
        }
    }
    return true;
}
bool colorNode(bool graph[101][101], int m, int n, int node, int color[]){
    if(node == n) return true;
    
    for(int i=1;i<=m;i++){
        if(isSafe(graph,n,i,node,color)){
            color[node] = i;
            if(colorNode(graph,m,n,node+1,color)) return true;
            else color[node] = 0;
        }
    }
    
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    int color[n] = {0};
    if(colorNode(graph,m,n,0,color)) return true;
    else return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
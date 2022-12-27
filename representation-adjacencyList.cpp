#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m;
    cout<<"Input no of nodes :";
    cin>>n;
    cout<<"Input no of edges :";
    cin>>m;
    
    cout<<"The no of nodes are : "<< n<<endl;
    cout<<"The no of edges are : "<< m<<endl;
    
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0;i<m;i++){
        cout<<i<<"->";
        for(int j=0; j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

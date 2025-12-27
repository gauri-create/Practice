//matrix method
#include<iostream>
#include<vector>
using namespace std;

// int main(){
//     int n, m;
//     cout<<"Enter node and edges count"<<endl;
//     cin>>n>>m;
//     int adj[n+1][n+1]={0};
//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u>>v;
//         adj[u][v]=1;
//         adj[v][u]=1;
//     }
//     cout<<"adjacency matrix"<<endl;
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n; j++){
//             cout<<adj[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

//Adjacency list(vector)
int main(){
    int n, m;
    cout<<"Enter nodes and edges count"<<endl;
    cin>>n>>m;

    vector<int>adj[n+1];

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    cout<<"Adjacency list"<<endl;
    for(int i=1; i<=n; i++){
        cout<<i<<"->";
        for(int j: adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}



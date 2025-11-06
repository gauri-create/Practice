#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
      /*Function to implement Bellmon Ford
       edges: vector of vectors which representsthe graph
       S: source vertex to start traversing graph with
       V: number of  vertices
        */

        vector<int> BellmanFord(int V, vector<vector<int>> & edges, int S){
            vector<int> dist(V, 1e8);
            dist[S]=0;
            for(int i=0;i<V-1;i++){
                for(auto it: edges){
                    int u = it[0];
                    int v = it[1];
                    int wt = it[2];
                    if(dist[u] != 1e8 && dist[u]+wt<dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }
            //Nth relaxation to check negative cycle
            for(auto it : edges){
                int u= it[0];
                int v= it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist [u]+wt <dist[v]){
                    return {-1};
                }
            }
            return dist;
        }
};

int main(){
    int V, E;
    cout<<"Number of vertices in  graph and edges ";
    cin>>V>>E;
    vector<vector<int>> edges(E, vector<int>(3));
    cout<<"Enter starting node of edges(u), destination node of edge(v), weight of edge(wt): ";
    for(int i=0; i<E; i++){
        cout<<"Enter u: ";
        cin>>edges[i][0];
        cout<<"Enter v: ";
        cin>>edges[i][1];
        cout<<"Enter wt: ";
        cin>>edges[i][2];
        //u v wt

    }
    
    int S;
    cout<<"Enter the node where shortest path calculation begins: ";
    cin>> S;

    Solution obj; //create object
    vector<int> result = obj.BellmanFord(V, edges, S);

    if(result.size()==1 && result[0]== -1){
        cout<<"Negative weight cycle detected";
    }
    else{
        for(int d: result){
            if(d==1e8) cout <<"INF ";
            else cout << d<<" ";
        }
    }
    return 0;
}


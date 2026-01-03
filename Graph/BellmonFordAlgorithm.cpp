#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    vector<int> bellman_ford(int V, vector<vector<int>> & edges, int S){
        vector<int>dist(V, 1e8);
        dist[S]=0;
        for(int i=0; i<V-1; i++){
            for(auto it: edges){
                int u = it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u] != 1e8 && dist[u] + wt<dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u] != 1e8 && dist[u] + wt<dist[v]) return {-1};
        }
        return dist;
    }
};

int main(){
    int V=6;
    vector<vector<int>> Edges={
        {3, 2, 6}, {5, 3, 1}, {0, 1, 5},
        {1, 5, -3}, {1, 2, -2}, {3, 4, -2}, {2, 4, 3}
    };
    int S=0;
    Solution obj;
    vector<int>ans=obj.bellman_ford(V, Edges, S);
    for(int i : ans) cout<<i<<" ";
    return 0;
}
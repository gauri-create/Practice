#include<iostream>
#include<vector>
using namespace std;

class Solution{
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col){
        for(int k=0; k<n; k++){
            if(k!=node && graph[k][node]==1 && color[k]==col){
                return false;
            }   
        }
        return true;
    }

    bool solve(int node, int color[],  int m, int N, bool graph[101][101]){
        if(node==N){
            return true;
        }
        for(int i=1; i<=m; i++){
            if(isSafe(node, color, graph, N, i)){
                color[node]=i;
                if(solve(node+1, color, m, N, graph)) return true;
                color[node]=0;
            }
        }
        return false;
    }
    public:

    //Functon to determine if graph can be coloured with at most M colors such that no two adjavcent vertices of graph are clored with same color
    bool graphColoring(bool graph[101][101], int m, int N){
        int color[N]={0};
        if(solve(0, color, m, N, graph)) return true;
        return false;
    }

};
int main() {
    Solution obj;

    int N = 4;   // number of nodes
    int M = 2;   // max colors allowed

    bool graph[101][101] = {0};

    // Example graph adjacency matrix
    // (Simple connected square)
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;
    graph[0][2] = graph[2][0] = 1;
    bool result = obj.graphColoring(graph, M, N);

    if(result)
        cout << "Graph can be colored with " << M << " colors.\n";
    else
        cout << "Graph CANNOT be colored with " << M << " colors.\n";

    return 0;
}

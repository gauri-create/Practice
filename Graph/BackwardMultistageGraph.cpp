#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 9999

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> cost(n+1, vector<int>(n+1));

    cout << "Enter cost adjacency matrix (use 9999 for no edge):\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> cost[i][j];
        }
    }

    vector<int> dist(n+1), d(n+1);

    dist[1] = 0; // starting node cost = 0

    // Backward DP
    for(int i = 2; i <= n; i++){
        int minCost = INF, prevNode = -1;
        for(int j = 1; j < i; j++){
            if(cost[j][i] != INF && dist[j] + cost[j][i] < minCost){
                minCost = dist[j] + cost[j][i];
                prevNode = j;
            }
        }
        dist[i] = minCost;
        d[i] = prevNode;
    }

    // Construct Path
    vector<int> path;
    int node = n;
    path.push_back(node);

    while(node != 1){
        node = d[node];
        path.push_back(node);
    }

    reverse(path.begin(), path.end());

    cout << "\nMinimum cost = " << dist[n] << endl;
    cout << "Path: ";
    for(int x : path) cout << x << " ";
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

#define INF 9999

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    // Cost adjacency matrix
    vector<vector<int>> cost(n+1, vector<int>(n+1));

    cout << "Enter cost matrix (use 9999 for no edge):\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> cost[i][j];
        }
    }

    vector<int> dist(n+1), d(n+1);

    dist[n] = 0;  // cost from destination to itself = 0

    // Forward DP from node n-1 down to 1
    for(int i = n-1; i >= 1; i--){
        int minCost = INF, nextNode = -1;
        for(int j = i+1; j <= n; j++){
            if(cost[i][j] != INF && cost[i][j] + dist[j] < minCost){
                minCost = cost[i][j] + dist[j];
                nextNode = j;
            }
        }
        dist[i] = minCost;
        d[i] = nextNode;
    }

    // Construct path
    vector<int> path;
    int node = 1;
    path.push_back(node);

    while(node != n){
        node = d[node];
        path.push_back(node);
    }

    cout << "\nMinimum cost = " << dist[1] << endl;
    cout << "Path: ";
    for(int x : path) cout << x << " ";

    return 0;
}

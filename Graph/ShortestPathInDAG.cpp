#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        vector<int> dist(n, 1e9), parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto &[next, w] : adj[node]) {
                if (dis + w < dist[next]) {
                    dist[next] = dis + w;
                    parent[next] = node;
                    pq.push({dist[next], next});
                }
            }
        }

        if (dist[n - 1] == 1e9) return {-1};

        vector<int> path;
        int cur = n - 1;
        while (parent[cur] != cur) {
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(0);
        reverse(path.begin(), path.end());

        return path;
    }
};

int main() {
    int N = 6;
    vector<vector<int>> edges = {
        {0,1,2},{0,4,1},{4,5,4},
        {4,2,2},{1,2,3},{2,3,6},{5,3,1}
    };

    Solution obj;
    vector<int> ans = obj.shortestPath(N, edges);
    for (int x : ans) cout << x << " ";
    return 0;
}

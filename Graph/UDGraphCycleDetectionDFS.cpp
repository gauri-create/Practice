#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, node, vis, adj) == true)
                    return true;
            }
            else if (adjacentNode != parent)
                return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        return dfs(1, -1, vis, adj);
    }
};

int main()
{
    int V = 4;
    vector<int> adj[] = {{1, 2}, {0}, {0, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    cout << (ans ? "True" : "False");
    return 0;
}

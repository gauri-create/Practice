#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    int timer=1;
    void dfs(int node, int parent,vector<int>&vis, vector<int>adj[], int tin[], int low[],vector<vector<int>>& bridges){
        vis[node] =1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({it, node});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
    public:
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& E){
        vector<int> adj[V];
        for(auto it: E){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(V, 0);
        int tin[V];
        int low[V];
        vector<vector<int>>bridges;
        dfs(0,-1,vis, adj, tin, low, bridges);
        return bridges;
    }
};

int main(){
    int V=4;
    vector<vector<int>>E={{0,1},{1,2},{2,0},{1,3}};
    Solution obj;
    vector<vector<int>> ans = obj.criticalConnections(V, E);
    for(auto it: ans){
        for(auto x: it) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
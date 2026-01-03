#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        int  sum=0;
        int vis[V]={0};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node=it.second;
            int weight=it.first;
            if(vis[node] == 1) continue;
            vis[node]=1;
            sum += weight;
            for(auto i: adj[node]){
                int adjNode = i[0];
                int edW = i[1];
                if(vis[adjNode]==0){
                    pq.push({edW, adjNode});
                }
            } 
        }
        return sum; 
    }
};

int main(){
    int v=4;
    vector<vector<int>> adj []={{{1,1}, {3,4}},{{0,1}, {2,2}}, {{1,2}, {3,3}}, {{0,4}, {2,3}}};
    Solution obj;
    int ans =obj.spanningTree(v, adj);
    cout<<ans;
    return 0;
}
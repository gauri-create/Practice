#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

class Solution{
    public:
    vector<int>dijkstra(int V, vector<vector<int>> adj[],  int s){
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0,  s});
        dist[s]=0;
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgW = it[1];

                if(dis + edgW <dist[adjNode]){
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis+edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }    
};

int main(){
    int v=2;
    vector<vector<int>>adj[] ={{{1,9}}, {{0,9}}};
    int s=0;
    Solution obj;
    vector<int> ans = obj.dijkstra(v, adj,s);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}
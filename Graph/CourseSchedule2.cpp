#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    vector<int>findOrder( int V, vector<vector<int>> prerequisites){
        vector<int>adj[V];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        int indegree[V]={0};
        for(int i=0; i<V; i++){
            for(auto it: adj[i]) indegree[it]++;
        }

        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size() == V) return topo;
        return {};
    }
};

int main(){
    int N=4;
    vector<vector<int>> adj={{1,0}, {2,1}, {3,2}};
    Solution obj;
    vector<int> ans= obj.findOrder(N, adj);
    for(auto it: ans) cout<< it<<" ";
    return 0;
}
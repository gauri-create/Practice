#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<int> eventualSafeNode(int V, vector<int>adj[]){
        vector<int>adjRev[V];
        int indegree[V]={0};
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }     
        queue<int>q;
        vector<int> safeNodes;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

int main(){
    int V=7;
    vector<int>adj[]={{1,2}, {2,3}, {5}, {0}, {5}, {}, {}};
    Solution obj;
    vector<int> ans= obj.eventualSafeNode(V, adj);
    for(auto i: ans) cout<<i<<" ";
    return 0;
}
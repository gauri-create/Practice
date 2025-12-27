#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    vector<int>bfsOfGraph(int V, vector<int>adj[]){
        int vis[V]={0};
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs; 
    } 
};

int main(){
    int V=5;
    vector<int>adj[]={{2,3,1},{0},{0,4},{0},{2}};
    Solution obj;
    vector<int> ans = obj.bfsOfGraph(V, adj);
    for(auto it: ans) cout<<it;
    return 0;
}
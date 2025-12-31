#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
    private:
    void dfs(int node, int vis[], stack<int>& st, vector<int>adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, vis, st, adj);
        }
        st.push(node);
    }

    public:
    vector<int> topoSort(int V, vector<int> adj[]){
        int vis[V]={0};
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main(){
    int V=6;
    vector<int>adj[]={{}, {}, {3}, {1}, {0,1}, {0,2}};
    Solution obj;
    vector<int> ans = obj.topoSort(V, adj);
    for(auto it:ans){
       cout<<it<<" ";
       
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    bool dfs(int node, int col, int color[], vector<int>adj[]){
        color[node]=col;
        for(auto it: adj[node]){
            if(color[it] == -1){
                if(dfs(it, !col, color, adj)==false)return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }

    public:
    bool isBipartite(int V, vector<int>adj[]){
        int color[V];
        for(int i=0;i<V; i++) color[i]=-1;
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, adj)==false) return false;
            }
        }
        return true;
    }
};

int main(){
    int V=4;
    vector<int>adj[]={{1,3},{0,2},{1,3},{0,2}};
    Solution obj;
    bool ans = obj.isBipartite(V, adj);
    cout<<(ans?"True":"False");
    return 0;
}
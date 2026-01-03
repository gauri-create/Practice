#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    public:
    vector<int>rank, size, parent;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node] =  findUpar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] <rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return ;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution{
    public:
    int solve(int n, vector<vector<int>>& edge){
        DisjointSet ds(n);
        int cntExtras=0;
        for(auto it: edge){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u) == ds.findUpar(v)) cntExtras++;
            else ds.unionBySize(u, v);
        }
        int cntC = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i) cntC++;
        }   
        int ans = cntC-1;
        if(cntExtras >= ans)return ans;
        return -1;
    }
};

int main(){
    int n=4;
    vector<vector<int>> edge={{0,1}, {0,2}, {1,2}};
    Solution obj;
    int ans = obj.solve(n, edge);
    cout<<ans;
    return 0;
}
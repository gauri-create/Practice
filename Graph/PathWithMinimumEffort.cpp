#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution{
    public:
    int MinimumEffort(vector<vector<int>> &heights){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,  int>>>, greater<pair<int, pair<int, int>>>>q;

        int n=heights.size();
        int m= heights[0].size();

        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        
        dist[0][0]=0;
        q.push({0,{0,0}});

        int dr[]={-1, 0, 1, 0};
        int dc[]={0, 1, 0, -1}; 


        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int diff = it.first;
            int r= it.second.first;
            int c= it.second.second;

            if( r == n-1 && c == m-1) return diff;
            for(int i=0; i<4; i++){
                int newr = r+dr[i];
                int newc = c+dc[i];
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m ){
                    int newEffort = max(abs(heights[r][c]-heights[newr][newc]), diff);
                    if(newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        q.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    vector<vector<int>>heights={
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };
    Solution obj;
    int ans = obj.MinimumEffort(heights);
    cout<<ans;
    return 0;
}
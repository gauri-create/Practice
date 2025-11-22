#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>>CombinationSum3(int k, int n){
        vector<vector<int>>ans;
        vector<int>ds;
        dfs(1,k,n,0,ds,ans);
        return ans;
    }

    private:
    void dfs(int start, int k, int target, int sum, vector<int>&ds,vector<vector<int>>&ans){

        if(sum>target)return;
        if(ds.size()>k)return ;

        if(sum==target && ds.size()==k){
            ans.push_back(ds);
            return ;
        }
        for(int i=start; i<=9; i++){
            ds.push_back(i);
            dfs(i+1, k, target, sum+i, ds, ans);
            ds.pop_back();
        }
    }

};

int main(){
    int n=9;
    int k=3;
    Solution obj;
    vector<vector<int>> ans= obj.CombinationSum3(k, n);
    for(auto x: ans){
        cout<<"[";
        for(auto i: x){
            cout<<i<<" ";
        }
        cout<<"]";
    }
}
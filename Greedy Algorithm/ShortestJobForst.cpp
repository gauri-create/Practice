#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    long long solve(vector<int>& bt){
        int n=bt.size();
        sort(bt.begin(), bt.end());
        int t=0, wtTime=0;
        for(int i=0; i<n; i++){
            wtTime += t;
            t += bt[i];
        }
        return (wtTime/n);
    }
};

int main(){
    Solution obj;
    vector<int>bt={1, 2, 3, 4};
    long long ans= obj.solve(bt);
    cout<<ans;
    return 0;
}
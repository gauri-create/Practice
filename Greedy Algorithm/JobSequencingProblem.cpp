#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs){
        int n= Jobs.size();
        sort(Jobs.begin(), Jobs.end(), 
            [](auto &a, auto &b){
                return a[2]>b[2];
            }
        );

        int maxi = 0;
        for(auto &j : Jobs){
            maxi=max(maxi, j[1]);
        }

        vector<int>slot(maxi+1, -1);
        int countJobs=0, jobProfit=0;

        for(int i=0; i<n; i++){
            for(int j=Jobs[i][1]; j>0; j--){
                if(slot[j]==-1){
                    slot[j]=i;
                    countJobs++;
                    jobProfit += Jobs[i][2];
                    break;
                }
            }
        }
        return {countJobs, jobProfit};
    }
};

int main(){
    Solution obj;
    vector<vector<int>> jobs = {{1,4,20}, {2,1,10}, {3,1,40}, {4,1,30}};
    vector<int> ans = obj.JobScheduling(jobs);
    for(int c: ans) cout<<c<<endl;
    return 0;
}


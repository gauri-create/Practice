#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        int i=0;
        int n=Intervals.size();
        while(i<n && Intervals[i][1]<newInterval[0]){
            res.push_back(Intervals[i]);
            i++;
        }
        while(i<n && Intervals[i][0]<newInterval[1]){
            newInterval[0]=min(newInterval[0], Intervals[i][0]);
            newInterval[1]=max(newInterval[1], Intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while(i<n){
            res.push_back(Intervals[i]);
            i++;
        }
        return res;
    }

};

int main(){
    Solution obj;
    vector<vector<int>> interval={{1,3}, {6,9}};
    vector<int> newInterval={2,5};
    vector<vector<int>> ans = obj.insertNewInterval(interval, newInterval);
    for(auto x : ans){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
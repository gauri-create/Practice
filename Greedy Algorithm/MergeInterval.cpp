#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0){
            return mergedIntervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<int>tempIntervals = intervals[0];

        for(auto it: intervals){
            if(it[0]<=tempIntervals[1]){
                tempIntervals[1]=max(it[1], tempIntervals[1]);
            }
            else{
                mergedIntervals.push_back(tempIntervals);
                tempIntervals=it;
            }
        }
        mergedIntervals.push_back(tempIntervals);
        return mergedIntervals;
    }
};

int main(){
    Solution obj;
    vector<vector<int>>intervals={{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>>ans = obj.mergeIntervals(intervals);
    for(auto x : ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
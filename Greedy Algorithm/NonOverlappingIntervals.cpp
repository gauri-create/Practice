#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals){
        int n=Intervals.size();
        int cnt=1;
        sort(Intervals.begin(), Intervals.end());
        int lastEndTime=Intervals[0][1];
        for(int i=1; i<n; i++){
            if(Intervals[i][0]>= lastEndTime){
                cnt++;
                lastEndTime=Intervals[i][1];
            }
        }
        return n-cnt;
    }

};

int main(){
    Solution obj;
    vector<vector<int>> Intervals={{1,3}, {1,4}, {3,5},{3,4},{4,5}};
    int ans= obj.MaximumNonOverlappingIntervals(Intervals);
    cout<<ans;
    return 0;
}
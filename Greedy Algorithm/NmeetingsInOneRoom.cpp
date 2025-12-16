#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<int> maxMeetings(vector<int>& start, vector<int>& end){
        vector<tuple<int, int, int>> meetings;
        for(int i=0; i<start.size();i++){
            meetings.push_back({end[i], start[i], i});
        }
        sort(meetings.begin(), meetings.end());
        vector<int> result;
        int lastEnd=-1;
        for(auto& m: meetings){
            int e= get<0>(m);
            int s=get<1>(m);
            int idx = get<2>(m);

            if(s>=lastEnd){
                result.push_back(idx);
                lastEnd=e;
            }
        }
        return result;
    }

    int maxMeetings1(vector<int>& start, vector<int>& end){
        vector<tuple<int, int, int>> meetings;
        int cnt=0;
        for(int i=0; i<start.size();i++){
            meetings.push_back({end[i], start[i], i});
        }
        sort(meetings.begin(), meetings.end());
        vector<int> result;
        int lastEnd=-1;
        for(auto& m: meetings){
            int e= get<0>(m);
            int s=get<1>(m);
            int idx = get<2>(m);

            if(s>=lastEnd){
                cnt++;
                result.push_back(idx);
                lastEnd=e;
            }
        }
        return cnt ;
    }
};

int main(){
    Solution obj;
    vector<int> start={1, 3, 0, 5, 8, 5};
    vector<int>end = {2, 4, 6, 7, 9, 9};

    vector<int> res=obj.maxMeetings(start, end);
    int ans=obj.maxMeetings1(start, end);
    cout<<ans<<endl;
    for(int idx: res) cout<<idx<<" ";
    return 0;
}
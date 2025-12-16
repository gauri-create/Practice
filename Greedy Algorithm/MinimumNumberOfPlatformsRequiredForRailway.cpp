#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());
        int i=0, j=0, cnt=0, maxcnt=0, n=Arrival.size() ;
        while(i<n){
            if(Arrival[i]<=Departure[j]){
                cnt++;
                i++;
            }
            else {
                cnt--;
                j++;
            }
            maxcnt=max(maxcnt, cnt);
        }
        return maxcnt;
    }

};

int main(){
    Solution obj;
    vector<int> Arrival={900, 940, 950, 1100, 1500, 1800};
    vector<int> Departure={910, 1200, 1120, 1130, 1900, 2000};
    int ans = obj.findPlatform(Arrival, Departure);
    cout<<ans;
    return 0;
}
#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;
//brute

//better
long double MinimizeMaxDistance2(vector<int> &arr, int k){
    int n=arr.size();
    vector<int>HowMany(n-1,0);
    priority_queue<pair<long double, int>> pq;
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i], i});
    }
    for(int gasStations=1; gasStations<=k; gasStations++){
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        HowMany[secInd]++;
        long double iniDiff = arr[secInd+1]-arr[secInd];
        long double newSecLen = iniDiff/(long double)(HowMany[secInd]+1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}

//optimal
int NumberOfGasStationsRequired(long double dist, vector<int> &arr){
    int cnt=0;
    for(int i=1; i<arr.size(); i++){
         int NumberInBetween=((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])/dist== NumberInBetween * dist){
            NumberInBetween--;
        }
        cnt+= NumberInBetween;
    }
    return cnt;
}

long double MinimizemaxDistance3( vector<int> &arr, int k){

    int n=arr.size();
    long double low=0;
    long double high=0;
    for(int i=0; i<n-1; i++){
        high=max(high,(long double)(arr[i+1]-arr[i]));
    }
    long double diff=1e-6;
    while(high-low>diff){
        long double mid((low+high) / (2.0));
        int cnt = NumberOfGasStationsRequired(mid, arr);
        if(cnt>k){
            low=mid;
        }
        else{
            high=mid;
        }

    }
    return high;
}


int main(){
    int n, k;
    cout<<"Enter number of points: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter sorted positions: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());


    cout<<"Enter number of extragas stations: ";
    cin>>k;

    // long double ans= MinimizeMaxDistance2(arr, k);
    long double ans= MinimizemaxDistance3(arr, k);

    cout<<"Minimum possible maximum distance: "<<ans<<endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

bool possible(vector<int> &arr, int day, int k, int m ){
    int cnt=0;
    int no0f8=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] <= day){
             cnt++;
        }
        else{
            no0f8 += (cnt/k);
            cnt=0;
        }
    }
        no0f8+=(cnt/k);
        return no0f8>=m;
    

}

int roseGuarden(vector<int> arr, int k, int m){
    long long val = k*1LL*m*1LL;
    if(val>arr.size()) return -1;
    int mini=INT_MAX, maxi=INT_MIN;
    for(int i=0; i<arr.size(); i++){
        mini=min(mini, arr[i]);
        maxi=max(maxi,arr[i]);
    }
    int low=mini, high=maxi, ans;
    while(low<=high){
        int mid = (low+high)/2;
        if(possible(arr, mid, k, m)){
            ans=mid;
             high=mid-1;
        }
        else low=mid+1;

    }
    return low;
}

int main(){
    int no=0;
    int m, k;
    cout<<"Enter size of array";
    cin>>no;
    vector<int> arr(no);
    cout<<"Enter blooming days array elements:"<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    cout<<"Enter No. of bouquets: ";
    cin>>m;
    cout<<"Enter number of adjacent flowers: ";
    cin>>k;
    int ret=roseGuarden(arr, k, m);
    cout<<"No. of the days required for making bouqets :"<<ret;
    return 0;
}
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int findMax(vector<int> &v){
    int maxi =INT_MIN;
    int n=v.size();
    for(int i=0; i<n; i++){
         maxi=max(maxi, v[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &v, int hourly){
    int totalH = 0;
    int n=v.size();
    for(int i= 0; i<n; i++){
         totalH+=ceil((double)v[i]/(double)hourly);
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h){
     int low=1, high=findMax(v);
     while(low<=high){
        int mid=(low+high)/2;
        int totalH=calculateTotalHours(v,mid);
        if(totalH <= h){
            high=mid-1;
        }
        else{
             low=mid+1;
        }
    }
    return low;
}

int  main(){
    int no;
    int hr;
    cout<<"Enter size of array: ";
    cin>>no;
    vector<int> arr(no);
    cout<<"Enter array elements (No. of bananas) : ";
    for(int i=0; i<no; i++){
         cin>>arr[i];
    }
    cout<<"Enter hr :";
    cin>>hr;
    int ret=minimumRateToEatBananas(arr, hr);
    cout<<"Number of bananas per hr is: "<<ret;
    return 0;

}
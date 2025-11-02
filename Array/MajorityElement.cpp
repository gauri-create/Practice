#include <bits/stdc++.h>
using namespace std;

int MajElement1(vector<int> arr, int n){
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(arr[i]==arr[j]) cnt++;
        
        }
        if(cnt>n/2) return arr[i];
    }
    return -1;
}

int MajElement2(vector<int> arr, int n){
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second > n/2){
            return it.first;
        }
    
    }
    return -1;
}

int MajElement3(vector<int> arr, int n){
    int cnt = 0;
    int el;
    for(int i=0; i<n; i++){
        if(cnt==0){
        cnt=1;
        el=arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    } 
    int cnt1=0;
    for(int i=0; i<n;i++){
        if(arr[i]==el) cnt1++;
    }
    if(cnt1> n/2) return el;
    return -1;
}

int main(){
    int no=0;
    cout<<"Enter size of array";
    cin>>no;

    vector<int> arr(no);
    cout<<"Enter array elements";
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    // int ret =  MajElement1(arr, no);
    // int ret =  MajElement2(arr, no);
    int ret =  MajElement3(arr, no);

    cout<<"Majority Element is:" <<ret;
    
    return 0;
}
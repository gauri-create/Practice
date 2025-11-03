#include<iostream>
#include<vector>
using namespace std;

int MaxSubArrayProduct(vector<int> arr, int n){
    int pre=1; 
    int suff=1;
    int ans=INT_MIN;
    for(int i=0; i<n; i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;

        pre = pre * arr[i];
        suff = suff * arr[n-i-1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main(){
    int no=0;
    cout<<"Enter size of array: ";
    cin>>no;
    vector<int>arr(no);
    cout<<"Enter array elements:"<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }

    int ret=MaxSubArrayProduct(arr,no);
    cout<<"The maximum product subarray is: "<<ret;
    return 0;
}
#include <iostream>
#include<vector>
#include<map>
using namespace std;

int CountAllSubArray(vector<int>arr, int n, int k){
    map<int, int>mpp;
    mpp[0]=1;
    int preSum =0;
    int cnt=0;
    for(int i=0; i<n; i++){
    preSum+=arr[i];
    int remove=preSum-k;
    cnt+=mpp[remove];
    mpp[preSum]+=1;

    }
    return cnt;
}

int main(){
    int no=0;
    cout<<"Enter array size: ";
    cin>>no;
    vector<int>arr(no);
    cout<<"Enter array elements:"<<endl;
    for(int i=0; i<no; i++){
        cin>>arr[i];
    }
    int k=0;
    cout<<"Enter sum: ";
    cin>>k;

    int ret = CountAllSubArray(arr, no, k);
    cout<<"Total subarrays with given sum is : "<<ret;
}